#pragma once
#include "Sync_queue.h"
#include "ClientCommand.h"

namespace syncedQueue{
	static Sync_queue<ClientCommand> queue;//static should be removed... right?
}