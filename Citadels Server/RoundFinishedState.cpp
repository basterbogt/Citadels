#include "RoundFinishedState.h"
#include "GameManager.h"
#include "GameRunningState.h"
#include "CharacterSelectionState.h"
RoundFinishedState::RoundFinishedState()
{
	/* Class that will check if the game is finished, by checking the bool method 'IsGameFinished' in the GameManager.
	If so, switch the GameManager state to 'FinishedState'

	(During this round, if someome gets his 8th building, mark the game as finished in the GameManager class by calling
	the method 'MarkAsFinished();')


	Also:
	Reset character cards;
	*/


}

void RoundFinishedState::Handle(GameRunningState& context, GameManager& gm){

	// discarded rounds terughalen
	vector<shared_ptr<CharacterCard>> discardedPile = gm.GetCardManager()->GetCharacterCardDiscardPile()->TakeCardPile();
	gm.GetCardManager()->GetCharacterCardPile()->AddCardPile(discardedPile);


	// karakterkaarten van iedereen afpakken en terug op de standaardlijst
	for (int i{ 0 }; i < gm.GetPlayerList()->Size(); i++) {
		vector<shared_ptr<CharacterCard>> pile = gm.GetPlayerList()->GetPlayerAt(i)->GetCharacterCardContainer()->TakeCardPile();

		for (auto &card : pile) {
			gm.GetCardManager()->GetCharacterCardPile()->Push_Back(card);
		}
		
	}


	// Has the game been finished?
	for (int i{ 0 }; i < gm.GetPlayerList()->Size(); i++) {
		shared_ptr<Player> player = gm.GetPlayerList()->GetPlayerAt(i);

		if (player->GetDistrictCardContainer()->Size() >= 8) {
			gm.MarkGameAsFinished();
			break;
		}
	}


	if (!gm.IsGameFinished()) {
		// dit niet doen als de game gefinished is, obviously!
		context.setState(shared_ptr < IRoundState > { new CharacterSelectionState});

	}

}

RoundFinishedState::~RoundFinishedState()
{
}
