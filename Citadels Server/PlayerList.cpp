#include "PlayerList.h"
#include <algorithm>

PlayerList::PlayerList()
{

}



shared_ptr<Player> PlayerList::GetPlayerAt(int position){
	if (position < 0 || position >= Size()) return nullptr;
	return m_PlayerList.at(position);
}

shared_ptr<Player> PlayerList::GetPlayerByRole(eCharacterCard card){
	shared_ptr<Player> player{ nullptr };
	for (int i = 0; i < m_PlayerList.size() && player == nullptr; i++){
		if (m_PlayerList.at(i)->HasCharacterCard(card)){
			player = m_PlayerList.at(i);
		}
	}
	return player;
}
shared_ptr<Player> PlayerList::GetPlayerByName(string name){
	shared_ptr<Player> player{ nullptr };
	for (int i = 0; i < m_PlayerList.size() && player == nullptr; i++){
		if (m_PlayerList.at(i)->GetName() == name){
			player = m_PlayerList.at(i);
		}
	}
	return player;
}
void PlayerList::InsertPlayer(shared_ptr<Player> player){
	m_PlayerList.push_back(player);
}
void PlayerList::RemovePlayer(shared_ptr<Player> player){

	auto position = std::find(m_PlayerList.begin(), m_PlayerList.end(), player);
	if (position != m_PlayerList.end()){
		m_PlayerList.erase(position);
	}

}
int PlayerList::Size(){
	return m_PlayerList.size();
}

PlayerList::~PlayerList()
{
}
