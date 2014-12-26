#include "ThiefState.h"


ThiefState::ThiefState()
{
}

void ThiefState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

ThiefState::~ThiefState()
{
}
