#include "ArchitectState.h"


ArchitectState::ArchitectState()
{

}

void ArchitectState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

eCharacterCard ArchitectState::currentRole() {
	return Architect;
}

ArchitectState::~ArchitectState()
{

}
