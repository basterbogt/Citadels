#include "BishopState.h"
#include "IRoundState.h"
#include "GameRunningState.h"
#include "RoundFinishedState.h"
#include "MerchantState.h"

BishopState::BishopState()
{
}

void BishopState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);

	m_CurrentPlayer->GiveGPForCards(blue);
	context.setState(unique_ptr < IRoundState > {new MerchantState});
}

eCharacterCard BishopState::currentRole() {
	return Bishop;
}


BishopState::~BishopState()
{
}
