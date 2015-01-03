#include "MerchantState.h"
#include "GameRunningState.h"
#include "ArchitectState.h"
MerchantState::MerchantState()
{
}

void MerchantState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
	m_CurrentPlayer->GiveGoldPieces(1);
	m_CurrentPlayer->GiveGPForCards(green);

	context.setState(unique_ptr < IRoundState > {new ArchitectState});

}

MerchantState::~MerchantState()
{
}

eCharacterCard MerchantState::currentRole() {
	return Merchant;
}
