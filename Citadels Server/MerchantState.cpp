#include "MerchantState.h"


MerchantState::MerchantState()
{
}

void MerchantState::Handle(IGameState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
}

MerchantState::~MerchantState()
{
}
