#include "IRoundState.h"
#include "GameManager.h"

void IRoundState::Handle(GameRunningState& context, GameManager& gm){
	m_CurrentPlayer = gm.GetPlayerList()->GetPlayerByRole(currentRole());
	
	m_CurrentPlayer->Send(gm.GetCardManager()->CharacterEnumToString(currentRole()) + "'s turn:\n");
	gm.GetPlayerList()->SendAllBut(m_CurrentPlayer, gm.GetCardManager()->CharacterEnumToString(currentRole()) + "'s turn, please wait...\n");


	if (m_CurrentPlayer == nullptr || gm.isKilled(currentRole())) {
		gm.GetPlayerList()->SendAll("Hmm... nothing happend.");
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
				m_CurrentPlayer->Send("Sorry, district card pile is empty. You receive nothing. #getRekt");
			}

			break;
		}
	}

	if (m_CurrentPlayer->GetDistrictCardContainer()->Size() > 0) {
		int wallet = m_CurrentPlayer->GetGoldPieces();

		int result = m_CurrentPlayer->RequestInput("Would you like to build something?", vector < string > {"Yes", "No"});

		if (result == 1) {
			return;
		}

		vector<string> answers;

		for (int i{ 0 }; m_CurrentPlayer->GetDistrictCardContainer()->Size(); i++) {
			
			shared_ptr<DistrictCard> card = m_CurrentPlayer->GetDistrictCardContainer()->At(i);

			answers.push_back(card->GetName() + " - Price: " + std::to_string(card->getCost()));

		}

		
		int result2 = m_CurrentPlayer->RequestInput("What do you want to build? [wallet: " + std::to_string(wallet) + "gp]", answers);
		shared_ptr<DistrictCard> cardToUse = m_CurrentPlayer->GetDistrictCardContainer()->Take(result2);

		if (cardToUse->getCost() > wallet) {
			m_CurrentPlayer->GetDistrictCardContainer()->Push_Back(cardToUse);
			m_CurrentPlayer->Send("Whoops, you do not have enough money!");
		}
		else {
			m_CurrentPlayer->SetGoldPieces(m_CurrentPlayer->GetGoldPieces() - cardToUse->getCost());
			m_CurrentPlayer->GetCityCardContainer()->Push_Back(cardToUse);
			m_CurrentPlayer->Send(cardToUse->GetName() + " has been added to your city!");
		}

	}

	
	//IRoundState::Handle(context, gm);
}