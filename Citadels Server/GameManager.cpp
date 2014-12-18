#include "GameManager.h"
#include <exception>
#include "SyncedQueue.h"
#include "LobbyState.h"

using std::exception;
using std::cerr;
using namespace syncedQueue;


GameManager::GameManager()
{
	m_PlayerListContainer = shared_ptr<PlayerList> {new PlayerList};
	m_CurrentGameState = unique_ptr<IGameState> {new LobbyState};
}



void GameManager::GameLoop()
{

	while (m_Playing)
	{
		m_CurrentGameState->Handle(*this);
	}


}


void GameManager::SetGamestate(unique_ptr<IGameState> state){
	m_CurrentGameState = std::move(state);
}

void GameManager::Exit(){
	m_Playing = false;
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

shared_ptr<PlayerList> GameManager::GetPlayerList(){
	return m_PlayerListContainer;
}

GameManager::~GameManager()
{
}
