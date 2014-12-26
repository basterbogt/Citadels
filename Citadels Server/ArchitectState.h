#pragma once
#include "IRoundState.h"
class ArchitectState :
	public IRoundState
{
public:
	ArchitectState();
	void Handle(GameRunningState& context, GameManager& gm);
	~ArchitectState();
};

