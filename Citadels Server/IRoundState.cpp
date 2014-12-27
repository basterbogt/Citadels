#include "IRoundState.h"
#include "GameManager.h"

void IRoundState::Handle(GameRunningState& context, GameManager& gm){
	eCharacterCard role = currentRole();

	m_CurrentPlayer = gm.GetPlayerList()->GetPlayerByRole(role);

	if (m_CurrentPlayer == nullptr || gm.isKilled(currentRole())) {
		return;
	}

	vector<string> answers = { "Receive 2 goldpieces", "Receive district card" };
	int result = m_CurrentPlayer->RequestInput("What do you want to do?", answers);

	switch (result) {
		case 0:
		{
			m_CurrentPlayer->GiveGoldPieces(2);
			m_CurrentPlayer->Send("You received 2 goldpieces.");
			break;
		}
		case 1:
		{
			m_CurrentPlayer->Send("Sorry, not implemented yet. You receive nothing. ggwp");
			break;
		}
	}

	
	//IRoundState::Handle(context, gm);
}