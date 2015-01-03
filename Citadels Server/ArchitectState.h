#pragma once
#include "IRoundState.h"
class ArchitectState :
	public IRoundState
{
public:
	ArchitectState();
	void Handle(GameRunningState& context, GameManager& gm);
	void PickDistrictCard(shared_ptr<CardPile<DistrictCard>> cp);
	void BuildSomething();
	eCharacterCard currentRole();
	~ArchitectState();
};

