#include "KingState.h"


KingState::KingState()
{
}

void KingState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

KingState::~KingState()
{
}
