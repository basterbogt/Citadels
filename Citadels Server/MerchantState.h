#pragma once
#include "IRoundState.h"
class MerchantState :
	public IRoundState
{
public:
	MerchantState();
	void Handle(IGameState& context, GameManager& gm);
	~MerchantState();
};

