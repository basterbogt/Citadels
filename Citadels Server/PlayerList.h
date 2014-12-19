#pragma once
#include "Player.h"
#include <memory>
#include <vector>

using std::vector;
using std::string;
using std::shared_ptr;


class PlayerList
{
private:
	vector<shared_ptr<Player>> m_PlayerList;
	vector<shared_ptr<int>> m_Temp;
public:
	PlayerList();

	shared_ptr<Player> GetPlayerAt(int position);
	shared_ptr<Player> GetPlayerByRole(eCharacterCard card);
	shared_ptr<Player> GetPlayerByName(string name);
	void InsertPlayer(shared_ptr<Player> player);
	void RemovePlayer(shared_ptr<Player> player);
	int Size();

	virtual ~PlayerList();
};
