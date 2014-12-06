#include "GameLoop.h"

#include "stdafx.h"
#include "Socket.h"
#include <iostream>
#include <fstream>
#include <string>

#include <thread>
#include <exception>
#include <memory>

using namespace std;

GameLoop::GameLoop()
{
	getServerInformation();

	socket = new ClientSocket(m_IP, m_Port);
	shared_ptr<ClientSocket> server{ socket };

	while (true) { // game loop
		try {
			// read first line of request
			string cmd = server->readline();
			cerr << "server (" << server->get() << ") said: " << cmd << '\n';

			if (cmd == "Bye!") {
				break; // out of game loop, will end this thread and close connection
			}

			string input = "";
			getline(cin, input);
			cout << endl << input << endl;
			server->write(input + "\n");

		}
		catch (const exception& ex) {
			//server->write("ERROR: ");
			//server->write(ex.what());
			//server->write("\n");
		}
		catch (...) {
			//server->write("ERROR: something went wrong during handling of your request. Sorry!\n");
		}
	}

}

void GameLoop::getServerInformation(){
	std::string ip;
	const string textfile("config.txt");
	// input file stream, opent textfile voor lezen
	ifstream input_file(textfile);
	input_file >> ip >> m_Port;

	m_IP = new char[ip.size() + 1];
	m_IP[ip.size()] = 0;
	memcpy(m_IP, ip.c_str(), ip.size());
}

GameLoop::~GameLoop()
{

}
