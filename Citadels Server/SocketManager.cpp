#include "SocketManager.h"
#include "InputManager.h"

#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <memory>

#include "SyncedQueue.h"

using namespace std;
using namespace syncedQueue;

#include "Socket.h"
#include "Sync_queue.h"
#include "ClientCommand.h"

#include "GameManager.h"



void Start_GameLoop(shared_ptr<GameManager> gm) // runs in its own thread
{
	gm->GameLoop();
}

void handle_client(Socket* socket, shared_ptr<GameManager> gm) // this function runs in a separate thread
{
	shared_ptr<Socket> client{ socket };
	client->write("Welcome to Server 1.0! To quit, type 'quit'.\n");
	client->write(GET_PLAYER_INPUT);
	//client->write(socketexample::prompt);

	shared_ptr<Player> player{ new Player(client) };
	gm->setPlayer(player);

	while (true) { // game loop
		try {
			// read first line of request
			string cmd = client->readline();
			cerr << "client (" << client->get() << ") said: " << cmd << '\n';

			if (cmd == "quit") {
				client->write("Bye!\n");
				//client->write(socketexample::prompt);
				break; // out of game loop, will end this thread and close connection
			}

			ClientCommand command{ cmd, player, client };
			queue.put(command);

		}
		catch (const exception& ex) {
			client->write("ERROR: ");
			client->write(ex.what());
			client->write("\n");
		}
		catch (...) {
			client->write("ERROR: something went wrong during handling of your request. Sorry!\n");
		}
	}
}

SocketManager::SocketManager()
{
	getServerInformation();

	std::shared_ptr < GameManager > gm{ new GameManager };

	// start command consumer thread
	thread consumer{ Start_GameLoop, gm };
	consumer.detach(); // detaching is usually ugly, but in this case the right thing to do




	// create a server socket
	ServerSocket server(m_Port);

	while (true) {
		try {
			// wait for connection from client; will create new socket
			cerr << "server listening" << '\n';
			Socket* client = nullptr;

			while ((client = server.accept()) != nullptr) {
				// communicate with client over new socket in separate thread
				thread handler{ handle_client, client, gm };
				handler.detach(); // detaching is usually ugly, but in this case the right thing to do
				cerr << "server listening again" << '\n';
			}
		}
		catch (const exception& ex) {
			cerr << ex.what() << ", resuming..." << '\n';
		}
	}
}


SocketManager::~SocketManager()
{

}

void SocketManager::getServerInformation(){
	std::string ip;
	const string textfile("config.txt");
	// input file stream, opent textfile voor lezen
	ifstream input_file(textfile);
	input_file >> m_Port;

}