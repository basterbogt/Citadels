#pragma once

#include <string>
#include "Socket.h"
#include <memory>
#include "PlayerInput.h"

using std::shared_ptr;
using std::string;
using namespace Citadels;

class Player
{
private:
	string m_Name;
	int m_GoldPieces;
	shared_ptr<Socket> m_Socket;
public:
	Player(string name, shared_ptr<Socket> socket);

	void Send(string Message);
	void GetInput();
	string GetLastInput();

	virtual ~Player();
};

