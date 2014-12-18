#pragma once
#include "Sync_queue.h"
#include "ClientCommand.h"
#include "PlayerList.h"
#include "IGameState.h"

using std::unique_ptr;

class GameManager
{
private:
	shared_ptr<PlayerList> m_PlayerListContainer;
	unique_ptr<IGameState> m_CurrentGameState;
	bool m_Playing{true};
public:
	GameManager();

	void GameLoop();

	void SetGamestate(unique_ptr<IGameState> state);
	shared_ptr<PlayerList> GetPlayerList();

	string GameManager::GetPlayerInput(shared_ptr<Player> player);

	void Exit();

	~GameManager();
};

