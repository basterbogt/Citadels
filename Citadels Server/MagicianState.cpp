#include "MagicianState.h"
#include "GameManager.h"
#include "CardPile.h"
#include "GameRunningState.h"
#include "KingState.h"
MagicianState::MagicianState()
{
}

void MagicianState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
	if (m_CurrentPlayer.get() == nullptr || gm.isKilled(currentRole())) {
		context.setState(unique_ptr < IRoundState > {new KingState});
		return;
	}
	vector<string> answers = { "Switch Carts with player", "Dispose carts & get district cards" };
	int result = m_CurrentPlayer->RequestInput("Make a choice, Magician:", answers);

	switch (result) {
	case 0:
	{
		// Tja, je bent ook dom als je met jezelf gaat switchen... >.<
		vector<string> playerList;
		for (int i{ 0 }; i < gm.GetPlayerList()->Size(); i++) {
			playerList.push_back(gm.GetPlayerList()->GetPlayerAt(i)->GetName());
		}

		int playerPos = m_CurrentPlayer->RequestInput("Who's cards would you like?", playerList);
		shared_ptr<Player> victim = gm.GetPlayerList()->GetPlayerAt(playerPos);

		vector<shared_ptr<DistrictCard>> victimPile = victim->GetDistrictCardContainer()->TakeCardPile();
		vector<shared_ptr<DistrictCard>> myPile = m_CurrentPlayer->GetDistrictCardContainer()->TakeCardPile();
	
		victim->GetDistrictCardContainer()->AddCardPile(myPile);
		m_CurrentPlayer->GetDistrictCardContainer()->AddCardPile(victimPile);

		victim->Send("You have switched cards with " + m_CurrentPlayer->GetName());
		m_CurrentPlayer->Send("You have switched cards with " + victim->GetName());


		context.setState(shared_ptr < IRoundState > { new KingState });

		break;
	}
	case 1:
		m_CurrentPlayer->Send("Not implemented yet");
		context.setState(shared_ptr < IRoundState > { new KingState });
		break;

	
	}

}

MagicianState::~MagicianState()
{
}

eCharacterCard MagicianState::currentRole() {
	return Magician;
}
