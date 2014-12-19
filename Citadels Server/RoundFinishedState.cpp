#include "RoundFinishedState.h"


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

void RoundFinishedState::Handle(IGameState& context, GameManager& gm){

}

RoundFinishedState::~RoundFinishedState()
{
}
