#pragma once
#include "IRoundState.h"
class WarlordState :
	public IRoundState
{
public:
	WarlordState();
	void Handle(IGameState& context, GameManager& gm);
	~WarlordState();
};

