#include "ArchitectState.h"
#include "GameRunningState.h"
#include "BishopState.h"

ArchitectState::ArchitectState()
{

}

void ArchitectState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
	context.setState(unique_ptr < IRoundState > {new BishopState});
}

eCharacterCard ArchitectState::currentRole() {
	return Architect;
}

ArchitectState::~ArchitectState()
{

}
