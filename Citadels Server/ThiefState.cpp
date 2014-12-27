#include "ThiefState.h"
#include "GameManager.h"
#include "GameRunningState.h"
#include "MagicianState.h"
ThiefState::ThiefState()
{
}

void ThiefState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);

	shared_ptr<Player> player = gm.GetPlayerList()->GetPlayerByRole(Assassin);

	if (player.get() == nullptr || gm.isKilled(Thief)) {
		// switchen naar volgende state, want er is geen thief
		context.setState(unique_ptr < IRoundState > {new MagicianState});
		return;
	}

	vector<string> answers = { "Magican", "King", "Bishop", "Merchant", "Architect", "Warlord" };
	int result = player->RequestInput("Hi Thief, Which character would you like to rob?", answers);

	gm.setRobbed(eCharacterCard(result + 1));

	player->Send("You robbed the " + answers.at(result) + "\n");

	context.setState(unique_ptr < IRoundState > {new MagicianState});
}

ThiefState::~ThiefState()
{
}
