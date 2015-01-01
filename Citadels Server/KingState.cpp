#include "KingState.h"
#include "GameRunningState.h"
#include "BishopState.h"

KingState::KingState()
{
}

void KingState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
	m_CurrentPlayer->Send("Not implemented yet!");
	context.setState(unique_ptr < IRoundState > {new BishopState});
}


KingState::~KingState()
{
}

eCharacterCard KingState::currentRole() {
	return King;
}
