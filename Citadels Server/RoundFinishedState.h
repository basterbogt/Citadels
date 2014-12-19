#pragma once
#include "IRoundState.h"
class RoundFinishedState :
	public IRoundState
{
public:
	RoundFinishedState();
	void Handle(IGameState& context, GameManager& gm);
	~RoundFinishedState();
};

