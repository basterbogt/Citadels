#pragma once
#include "IGameState.h"
class FinishedState :
	public IGameState
{
public:
	FinishedState();
	void Handle(GameManager& gm);
	~FinishedState();
};

