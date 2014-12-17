#include "Player.h"

Player::Player(shared_ptr<Socket> socket)
{
	m_Socket = (socket);
}

void Player::setName(string name){
	m_Name = name;
}

void Player::Send(string Message){

}

void Player::AllowInput(){
	m_Socket->write(GET_PLAYER_INPUT);
}


Player::~Player()
{
}
