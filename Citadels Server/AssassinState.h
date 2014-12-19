#pragma once
#include "IRoundState.h"
class AssassinState :
	public IRoundState
{
public:
	AssassinState();
	void Handle(IGameState& context, GameManager& gm);
	~AssassinState();
};

