#include "WarlordState.h"


WarlordState::WarlordState()
{
}

void WarlordState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

WarlordState::~WarlordState()
{
}

eCharacterCard WarlordState::currentRole() {
	return Warlord;
}
