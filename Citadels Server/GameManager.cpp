#include "GameManager.h"
#include <exception>
#include "LobbyState.h"

using std::exception;
using std::cerr;


GameManager::GameManager()
{
	m_PlayerListContainer = shared_ptr<PlayerList> {new PlayerList};
	m_CurrentGameState = unique_ptr<IGameState> {new LobbyState};
	m_CardManager = unique_ptr < CardManager > {new CardManager};
}



void GameManager::GameLoop()
{
	while (true)
	{
		m_CurrentGameState->Handle(*this);
	}
}


void GameManager::SetGamestate(unique_ptr<IGameState> state){
	m_CurrentGameState = std::move(state);
}

void GameManager::MarkGameAsFinished(){
	m_IsFinished = true;
}

bool GameManager::IsGameFinished(){
	return m_IsFinished;
}




shared_ptr<PlayerList> GameManager::GetPlayerList(){
	return m_PlayerListContainer;
}
shared_ptr<CardManager> GameManager::GetCardManager(){
	return m_CardManager;
}

GameManager::~GameManager()
{
}
