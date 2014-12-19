#include "CardManager.h"

CardManager::CardManager()
{
	/*
	m_DistrictCardPile = shared_ptr<CardPile<DistrictCard>> { new CardPile<DistrictCard> };
	m_DistrictCardDiscardPile = shared_ptr<CardPile<DistrictCard>> { new CardPile<DistrictCard> };
	m_CharacterCardPile = shared_ptr<CardPile<CharacterCard>> { new CardPile<CharacterCard> };
	m_CharacterCardDiscardPile = shared_ptr<CardPile<CharacterCard>> { new CardPile<CharacterCard> };

	//TODO: Create all cards

	shared_ptr<CharacterCard> Assassin{ new CharacterCard("Assassin", eCharacterCard::Assassin) };
	shared_ptr<CharacterCard> Thief{ new CharacterCard("Thief", eCharacterCard::Thief) };
	shared_ptr<CharacterCard> Magician{ new CharacterCard("Magician", eCharacterCard::Magician) };
	shared_ptr<CharacterCard> King{ new CharacterCard("King", eCharacterCard::King) };
	shared_ptr<CharacterCard> Bishop{ new CharacterCard("Bishop", eCharacterCard::Bishop) };
	shared_ptr<CharacterCard> Merchant{ new CharacterCard("Merchant", eCharacterCard::Merchant) };
	shared_ptr<CharacterCard> Architect{ new CharacterCard("Architect", eCharacterCard::Architect) };
	shared_ptr<CharacterCard> Warlord{ new CharacterCard("Warlord", eCharacterCard::Warlord) };

	m_CharacterCardPile->Push_Back(Assassin);
	m_CharacterCardPile->Push_Back(Thief);
	m_CharacterCardPile->Push_Back(Magician);
	m_CharacterCardPile->Push_Back(King);
	m_CharacterCardPile->Push_Back(Bishop);
	m_CharacterCardPile->Push_Back(Merchant);
	m_CharacterCardPile->Push_Back(Architect);
	m_CharacterCardPile->Push_Back(Warlord);
	*/
}


shared_ptr<CardPile<DistrictCard>> CardManager::GetDistrictCardPile(){
	return m_DistrictCardPile;
}
shared_ptr<CardPile<DistrictCard>> CardManager::GetDistrictCardDiscardPile(){
	return m_DistrictCardDiscardPile;
}
shared_ptr<CardPile<CharacterCard>> CardManager::GetCharacterCardPile(){
	return m_CharacterCardPile;
}
shared_ptr<CardPile<CharacterCard>> CardManager::GetCharacterCardDiscardPile(){
	return m_CharacterCardDiscardPile;
}

CardManager::~CardManager()
{
}
