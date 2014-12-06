#pragma once
#include "Socket.h"
class GameLoop
{
private:
	char* m_IP;
	int m_Port;
	ClientSocket* socket;
	void getServerInformation();
public:
	GameLoop();
	~GameLoop();
};

