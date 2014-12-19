#include "BishopState.h"


BishopState::BishopState()
{
}

void BishopState::Handle(IGameState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

BishopState::~BishopState()
{
}
