#include "AssassinState.h"
#include "GameManager.h"


AssassinState::AssassinState()
{
}

void AssassinState::Handle(IGameState& context, GameManager& gm){
	IRoundState::Handle(context, gm);

	shared_ptr<Player> player = gm.GetPlayerList()->GetPlayerByRole(Assassin);

	if (player.get() == nullptr) {
		// switchen naar volgende state, want er is geen assassin
		return;
	}

	vector<string> answers = {"Thief", "Magican", "King", "Bishop", "Merchant", "Architect", "Warlord" };
	int result = player->RequestInput("Hi Assassin, Which character would you like to murder?", answers);

	// Since "Assassin" was not on our chacter list, the enum we need is answer + 1
	gm.setKilled(eCharacterCard(result + 1));

	player->Send("You killed the " + answers.at(result));


}

AssassinState::~AssassinState()
{
}
