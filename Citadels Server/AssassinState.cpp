#include "AssassinState.h"
#include "GameManager.h"
#include "GameRunningState.h"
#include "ThiefState.h"
AssassinState::AssassinState()
{
}

void AssassinState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);

	

	if (m_CurrentPlayer.get() == nullptr) {
		// switchen naar volgende state, want er is geen assassin
		context.setState(unique_ptr < IRoundState > {new ThiefState});
		return;
	}

	vector<string> answers = {"Thief", "Magican", "King", "Bishop", "Merchant", "Architect", "Warlord" };
	int result = m_CurrentPlayer->RequestInput("Hi Assassin, Which character would you like to murder?", answers);

	// Since "Assassin" was not on our chacter list, the enum we need is answer + 1
	gm.setKilled(eCharacterCard(result + 1));

	m_CurrentPlayer->Send("You killed the " + answers.at(result) + "\n");

	context.setState(unique_ptr < IRoundState > {new ThiefState});


}

eCharacterCard AssassinState::currentRole() {
	return Assassin;
}


AssassinState::~AssassinState()
{
}
