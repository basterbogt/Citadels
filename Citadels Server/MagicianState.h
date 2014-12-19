#pragma once
#include "IRoundState.h"
class MagicianState :
	public IRoundState
{
public:
	MagicianState();
	void Handle(IGameState& context, GameManager& gm);
	~MagicianState();
};

