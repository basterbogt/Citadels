#include "Player.h"

Player::Player(string name, shared_ptr<Socket> socket)
{
	m_Name = name;
	m_Socket = (socket);
}


void Player::Send(string Message){

}

void Player::GetInput(){
	m_Socket->write(GET_PLAYER_INPUT);
}
string Player::GetLastInput(){
	string result = PlayerInput[m_Socket->get()];
	PlayerInput[m_Socket->get()] = "";
	return result;
}

Player::~Player()
{
}
