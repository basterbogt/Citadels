#pragma once
#include "IRoundState.h"
class ThiefState :
	public IRoundState
{
public:
	ThiefState();
	void Handle(IGameState& context, GameManager& gm);
	~ThiefState();
};

