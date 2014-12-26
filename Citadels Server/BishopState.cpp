#include "BishopState.h"


BishopState::BishopState()
{
}

void BishopState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

BishopState::~BishopState()
{
}
