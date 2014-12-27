#include "MerchantState.h"


MerchantState::MerchantState()
{
}

void MerchantState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

MerchantState::~MerchantState()
{
}

eCharacterCard MerchantState::currentRole() {
	return Merchant;
}
