#pragma once
#include "Sync_queue.h"
#include "ClientCommand.h"

namespace syncedQueue{
	/* Doesnt work quite yet.. It looks as if this queue get's instantitated for each class/thread, or something */
	static Sync_queue<ClientCommand> queue;//static should be removed... right?
}