#pragma once
#include "Socket.h"

class SocketManager
{
private:
	int m_Port;
	void getServerInformation();
public:
	SocketManager();
	~SocketManager();
};

