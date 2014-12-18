#include "Player.h"

Player::Player(shared_ptr<Socket> socket)
{
	m_Socket = (socket);
}





shared_ptr<CardPile<CharacterCard>> Player::GetCharacterCardContainer(){
	return nullptr;//TODO
}
shared_ptr<CardPile<DistrictCard>> Player::GetDistrictCardContainer(){
	return nullptr;//TODO
}
bool Player::HasCharacterCard(eCharacterCard role){
	bool found = false;
	for (int i = 0; i < m_CharacterCards->Size() && !found; i++){
		found = m_CharacterCards->GetCardPile().at(i)->GetEnum() == role;
	}
	return found;
}



void Player::SetName(string name){
	m_Name = name;
}
string Player::GetName(){
	return m_Name;
}

void Player::Send(string message){
	m_Socket->write(message);
}

void Player::AllowInput(){
	m_Socket->write(GET_PLAYER_INPUT);
}


Player::~Player()
{
}
