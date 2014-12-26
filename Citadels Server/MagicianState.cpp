#include "MagicianState.h"


MagicianState::MagicianState()
{
}

void MagicianState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

MagicianState::~MagicianState()
{
}
