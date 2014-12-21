#include "GameRunningState.h"
#include "GameManager.h"
#include "IRoundState.h"
#include "CharacterSelectionState.h"

GameRunningState::GameRunningState()
{
}

void GameRunningState::Handle(GameManager& gm){
	


	vector<string> answers;
	answers.push_back("Barry");
	answers.push_back("Tony");
	answers.push_back("Eric");
	answers.push_back("Bert");

	std::cout << gm.GetPlayerList()->GetPlayerByName("bas")->RequestInput("Hoe heet ik?", answers) << std::endl;

	vector<string> answers2;
	answers2.push_back("Brt");
	answers2.push_back("Gert");
	answers2.push_back("Gik");
	answers2.push_back("stapel");

	std::cout << gm.GetPlayerList()->GetPlayerByName("gijs")->RequestInput("Hoe heet ik?", answers2) << std::endl;
	

	shared_ptr<CharacterSelectionState> currentRound{ new CharacterSelectionState };

	while (true){
		currentRound->Handle(*this, gm);
	}


}


GameRunningState::~GameRunningState()
{
}
