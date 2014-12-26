#pragma once

#include <memory>

using std::shared_ptr;

class GameManager;
class IGameState;
class GameRunningState;
class IRoundState
{
public:
	IRoundState(){}
	virtual void Handle(GameRunningState& context, GameManager& gm);
	virtual ~IRoundState(){}
};

