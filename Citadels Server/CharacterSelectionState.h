#pragma once
#include "IRoundState.h"
class CharacterSelectionState :
	public IRoundState
{
public:
	CharacterSelectionState();
	void Handle(IGameState& context, GameManager& gm);
	virtual ~CharacterSelectionState();
};

