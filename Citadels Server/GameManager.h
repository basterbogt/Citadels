#pragma once
#include "Sync_queue.h"
#include "ClientCommand.h"
#include "PlayerList.h"
#include "IGameState.h"
#include "CardManager.h"

using std::unique_ptr;

class GameManager
{
private:
	shared_ptr<PlayerList> m_PlayerListContainer;
	unique_ptr<IGameState> m_CurrentGameState;
	shared_ptr<CardManager> m_CardManager;
	bool m_IsFinished{false};
public:
	GameManager();

	void GameLoop();

	void SetGamestate(unique_ptr<IGameState> state);
	shared_ptr<PlayerList> GetPlayerList();
	shared_ptr<CardManager> GetCardManager();

	void MarkGameAsFinished();
	bool IsGameFinished();

	~GameManager();
};

