#pragma once

#include <memory>
#include "CharacterCard.h"
#include "Player.h"
using std::shared_ptr;

class GameManager;
class IGameState;
class GameRunningState;
class IRoundState
{
protected:
	shared_ptr<Player> m_CurrentPlayer;
public:
	IRoundState(){}
	virtual void Handle(GameRunningState& context, GameManager& gm);
	virtual ~IRoundState(){}
	virtual eCharacterCard currentRole() = 0;
};

