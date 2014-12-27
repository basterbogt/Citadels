#include "BishopState.h"


BishopState::BishopState()
{
}

void BishopState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

eCharacterCard BishopState::currentRole() {
	return Bishop;
}


BishopState::~BishopState()
{
}
