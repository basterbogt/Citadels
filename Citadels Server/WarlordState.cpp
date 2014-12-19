#include "WarlordState.h"


WarlordState::WarlordState()
{
}

void WarlordState::Handle(IGameState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

WarlordState::~WarlordState()
{
}
