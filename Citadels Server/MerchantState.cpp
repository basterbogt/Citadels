#include "MerchantState.h"


MerchantState::MerchantState()
{
}

void MerchantState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
	m_CurrentPlayer->GiveGoldPieces(1);
	m_CurrentPlayer->GiveGPForCards(green);

	m_CurrentPlayer->Send("Builder state not implemented yet!");
	//context.setState(unique_ptr < IRoundState > {new BuilderState});

}

MerchantState::~MerchantState()
{
}

eCharacterCard MerchantState::currentRole() {
	return Merchant;
}
