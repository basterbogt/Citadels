#pragma 
#include "ICard.h"

enum eCharacterCard { Assassin, Thief, Magician, King, Bishop, Merchant, Architect, Warlord };

class CharacterCard :
	public ICard
{
private:
	eCharacterCard m_Enum;
public:
	CharacterCard(eCharacterCard characterEnum);
	eCharacterCard GetEnum();
	virtual ~CharacterCard();
};

