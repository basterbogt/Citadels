// Citadels.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <crtdbg.h>
#include "GameLoop.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	GameLoop* loop = new GameLoop();
	delete loop;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}

