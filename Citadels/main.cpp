// Citadels.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Socket.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ClientSocket* socket = new ClientSocket("172.16.92.128", 1080);
	bool _playing = true;
	while (_playing){
		string cmd = socket->readline();
		cout << endl << cmd << endl;
		string input = "";
		getline(cin, input);
		cout << endl << input << endl;
		socket->write(input);
	}

	return 0;
}

