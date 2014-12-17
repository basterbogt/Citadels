#pragma once

#include <string>
#include "Socket.h"
#include <memory>

using std::shared_ptr;
using std::string;

class Player
{
private:
	string m_Name;
	int m_GoldPieces;
	shared_ptr<Socket> m_Socket;
public:
	Player(shared_ptr<Socket> socket);

	void setName(string name);
	void Send(string Message);
	void AllowInput();
	string GetLastInput();

	virtual ~Player();
};

