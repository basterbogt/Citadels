#include "MagicianState.h"


MagicianState::MagicianState()
{
}

void MagicianState::Handle(IGameState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

MagicianState::~MagicianState()
{
}
