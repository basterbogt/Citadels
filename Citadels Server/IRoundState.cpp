#include "IRoundState.h"
#include "GameManager.h"

void IRoundState::Handle(GameRunningState& context, GameManager& gm){
	eCharacterCard role = currentRole();

	m_CurrentPlayer = gm.GetPlayerList()->GetPlayerByRole(role);

	if (m_CurrentPlayer == nullptr || gm.isKilled(currentRole())) {
		return;
	}

	if (gm.isRobbed(currentRole())) {
		shared_ptr<Player> thief = gm.GetPlayerList()->GetPlayerByRole(Thief);
		int loot = m_CurrentPlayer->GetGoldPieces();
		m_CurrentPlayer->SetGoldPieces(0);
		thief->GiveGoldPieces(loot);

		thief->Send("Your illegally obtained loot is " + std::to_string(loot) + "gp");
		m_CurrentPlayer->Send("You have been robbed and lost all your gp (If you had any :P)");
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
			// rekening houden met een lege stapel!
			shared_ptr<CardPile<DistrictCard>> cp = gm.GetCardManager()->GetDistrictCardDiscardPile();

			if (cp->Size() >= 2) {
				vector < shared_ptr<DistrictCard> > choices {cp->Pop(), cp->Pop()};

				vector<string> answers = { choices.at(0)->GetName(), choices.at(1)->GetName() };
				int result = m_CurrentPlayer->RequestInput("Which card would you like to keep?", answers);

				int leftOver = 1 - result;

				m_CurrentPlayer->GetDistrictCardContainer()->Push_Back(choices.at(result));
				cp->Push_Back(choices.at(leftOver));

				m_CurrentPlayer->Send("You picked a " + choices.at(result)->GetName());

			
			}
			else if (cp->Size() == 1) {
				shared_ptr<DistrictCard> card1 = cp->Pop();
				m_CurrentPlayer->GetDistrictCardContainer()->Push_Back(card1);
				m_CurrentPlayer->Send("One card left, you picked a " + card1->GetName());
			}
			else {
				m_CurrentPlayer->Send("Sorry, district card pile is empty. You receive nothing. ggwp");
			}

			break;
		}
	}

	
	//IRoundState::Handle(context, gm);
}