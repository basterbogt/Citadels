#pragma once
#include "IRoundState.h"
class BishopState :
	public IRoundState
{
public:
	BishopState();
	void Handle(IGameState& context, GameManager& gm);
	~BishopState();
};

