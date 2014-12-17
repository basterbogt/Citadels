#include "GameManager.h"
#include <exception>
#include "SyncedQueue.h"

using std::exception;
using std::cerr;
using namespace syncedQueue;


GameManager::GameManager(){

}

void GameManager::GameLoop()
{
	int* i = 0;
	while (true){

		printf("BAS YO");
		printf(GetPlayerInput(m_Player).c_str());


	}

}


string GameManager::GetPlayerInput(shared_ptr<Player> player) 
{
	while (true) {
		ClientCommand command;
		queue.get(command); // will block here unless there still are command objects in the queue
		shared_ptr<Socket> client{ command.get_client() };
		if (client) {
			try {
				if (command.getPlayer() == player){
					return command.get_cmd();
				}
					//PlayerInput.put(client.get()->get(), command.get_cmd());
			}
			catch (const exception& ex) {
				client->write("Sorry, ");
				client->write(ex.what());
				client->write("\n");
			}
			catch (...) {
				client->write("Sorry, something went wrong during handling of your request.\n");
			}
			//client->write(socketexample::prompt);
		}
		else {
			cerr << "trying to handle command for client who has disappeared...\n";
		}
	}

}


GameManager::~GameManager()
{
}
