#include "CharacterCard.h"


CharacterCard::CharacterCard(eCharacterCard characterEnum) : m_Enum(characterEnum)
{

}


eCharacterCard CharacterCard::GetEnum(){
	return m_Enum;
}

CharacterCard::~CharacterCard()
{
}
