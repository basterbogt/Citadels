#include "ArchitectState.h"


ArchitectState::ArchitectState()
{

}

void ArchitectState::Handle(IGameState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

ArchitectState::~ArchitectState()
{

}
