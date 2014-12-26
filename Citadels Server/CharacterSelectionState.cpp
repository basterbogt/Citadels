#include "CharacterSelectionState.h"
#include "GameManager.h"
#include "GameRunningState.h"
CharacterSelectionState::CharacterSelectionState()
{
}

void CharacterSelectionState::Handle(IGameState& context, GameManager& gm){
	gm.GetCardManager()->GetCharacterCardPile()->Shuffle();

	gm.GetCardManager()->GetCharacterCardPile()->Pop();

	int AmountOfPlayers = gm.GetPlayerList()->Size();

	int i = 0;
	while (gm.GetCardManager()->GetCharacterCardPile()->Size() > 0){

		shared_ptr<Player> currentPlayer = gm.GetPlayerList()->GetPlayerAt(i % AmountOfPlayers);
		shared_ptr<CardPile<CharacterCard>> characterCardPile = gm.GetCardManager()->GetCharacterCardPile();
		if (i == 0) {
			gm.GetCardManager()->GetCharacterCardDiscardPile()->Push_Back(characterCardPile->Pop());
		}
		else{
			vector<string> answers;
			for (int i = 0; i < characterCardPile->Size(); i++){
				answers.push_back(characterCardPile->At(i)->GetName());
			}
			int result = currentPlayer->RequestInput("Which card would you like to discard?", answers);
			gm.GetCardManager()->GetCharacterCardDiscardPile()->Push_Back(characterCardPile->Take(result));
		}

		vector<string> answers;
		int pileSize = characterCardPile->Size();
		for (int i = 0; i < pileSize; i++){
			shared_ptr<ICard> card = characterCardPile->At(i);

			answers.push_back(card->GetName());
		}
		int result = currentPlayer->RequestInput("Which card would you like to keep?", answers);
		currentPlayer->GetCharacterCardContainer()->Push_Back(characterCardPile->Take(result));

		i++;
	}

}

CharacterSelectionState::~CharacterSelectionState()
{
}
