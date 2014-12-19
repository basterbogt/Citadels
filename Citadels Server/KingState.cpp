#include "KingState.h"


KingState::KingState()
{
}

void KingState::Handle(IGameState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

KingState::~KingState()
{
}
