#include <time.h>
#include <stdlib.h>
#include "SocketManager.h"

int main(int argc, const char * argv[])
{
	srand(time(0));
	SocketManager* sm = new SocketManager();
	delete sm;
    return 0;
}

