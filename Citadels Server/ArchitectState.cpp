#include "ArchitectState.h"
#include "GameRunningState.h"
#include "WarlordState.h"

ArchitectState::ArchitectState()
{
	printf("Architect State\n");
}

void ArchitectState::Handle(GameRunningState& context, GameManager& gm){
	IRoundState::Handle(context, gm);
	context.setState(unique_ptr < IRoundState > {new WarlordState});
}

eCharacterCard ArchitectState::currentRole() {
	return Architect;
}

ArchitectState::~ArchitectState()
{

}
void ArchitectState::PickDistrictCard(shared_ptr<CardPile<DistrictCard>> cp, int amount) {
	int askTimes = std::min<int>(cp->Size(), 2);

	for (int i{ 0 }; i < askTimes; i++) {
		IRoundState::PickDistrictCard(cp, amount);
	}
	
}


void ArchitectState::BuildSomething() {
	int askTimes = std::min<int>(m_CurrentPlayer->GetDistrictCardContainer()->Size(), 3);

	for (int i{ 0 }; i < askTimes; i++) {
		IRoundState::BuildSomething();

		if (i + 1 != askTimes) {
			continue;
		}

		int result = m_CurrentPlayer->RequestInput("Would you like to build another building?", vector < string > {"Yes", "No"});

		if (result == 1) {
			break;
		}
	}
}