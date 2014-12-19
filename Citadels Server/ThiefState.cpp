#include "ThiefState.h"


ThiefState::ThiefState()
{
}

void ThiefState::Handle(IGameState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

ThiefState::~ThiefState()
{
}
