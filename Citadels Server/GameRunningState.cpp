#include "GameRunningState.h"
#include "GameManager.h"
#include "IRoundState.h"
#include "CharacterSelectionState.h"

GameRunningState::GameRunningState()
{
}

void GameRunningState::Handle(GameManager& gm){
	
	/*
	int i = 0;

	vector<string> answers;
	answers.push_back("Barry");
	answers.push_back("Tony");
	answers.push_back("Eric");
	answers.push_back("Bert");

	printf(gm.GetPlayerList()->GetPlayerByName("bas")->RequestInput("Hoe heet ik?", answers).c_str());

	printf(gm.GetPlayerList()->GetPlayerByName("gijs")->RequestInput("Hoe heet ik?").c_str());
	*/
	shared_ptr<CharacterSelectionState> currentRound{ new CharacterSelectionState };

	while (true){
		currentRound->Handle(*this, gm);
	}


}


GameRunningState::~GameRunningState()
{
}
