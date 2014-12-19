#pragma once
#include "IRoundState.h"
class KingState :
	public IRoundState
{
public:
	KingState();
	void Handle(IGameState& context, GameManager& gm);
	~KingState();
};

