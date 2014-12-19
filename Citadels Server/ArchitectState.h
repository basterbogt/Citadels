#pragma once
#include "IRoundState.h"
class ArchitectState :
	public IRoundState
{
public:
	ArchitectState();
	void Handle(IGameState& context, GameManager& gm);
	~ArchitectState();
};

