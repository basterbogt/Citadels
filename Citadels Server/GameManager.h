#pragma once
#include "Sync_queue.h"
#include "ClientCommand.h"
class GameManager
{
private:
	shared_ptr<Player> m_Player;
public:
	GameManager();

	void GameLoop();
	void setPlayer(shared_ptr<Player> player){
		m_Player = player;
	}
	string GameManager::GetPlayerInput(shared_ptr<Player> player);

	~GameManager();
};

