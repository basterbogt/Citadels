#include "AssassinState.h"


AssassinState::AssassinState()
{
}

void AssassinState::Handle(IGameState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

AssassinState::~AssassinState()
{
}
