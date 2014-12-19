#pragma once

#include <memory>

using std::shared_ptr;

class GameManager;
class IGameState;
class IRoundState
{
public:
	IRoundState(){}
	void Handle(IGameState& context, GameManager& gm);
	virtual ~IRoundState(){}
};

