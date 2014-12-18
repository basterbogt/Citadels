#pragma once
#include "IGameState.h"
class GameRunningState :
	public IGameState
{
public:
	GameRunningState();
	void Handle(GameManager& gm);
	virtual ~GameRunningState();
};

