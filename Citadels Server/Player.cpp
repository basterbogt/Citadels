#include "Player.h"
//#include "SyncedQueue.h"
#include <exception>
#include "SocketManager.h"
using std::exception;


Player::Player(shared_ptr<Socket> socket)
{
	m_Socket = (socket);
}





shared_ptr<CardPile<CharacterCard>> Player::GetCharacterCardContainer(){
	return m_CharacterCards;//TODO
}
shared_ptr<CardPile<DistrictCard>> Player::GetDistrictCardContainer(){
	return m_DistrictCards;//TODO
}

shared_ptr<CardPile<DistrictCard>> Player::GetCityCardContainer() {
	return m_City;
}


bool Player::HasCharacterCard(eCharacterCard role){
	bool found = false;
	for (int i = 0; i < m_CharacterCards->Size() && !found; i++){
		found = m_CharacterCards->GetCardPile().at(i)->GetEnum() == role;
	}
	return found;
}



void Player::SetName(string name){
	m_Name = name;
}
string Player::GetName(){
	return m_Name;
}

void Player::Send(string message){
	m_Socket->write(message + "\n");
}

void Player::AllowInput(){
	m_Socket->write(GET_PLAYER_INPUT);
}


bool Player::ValidateAnswer(string input, vector<string> expectedAnswers){

	try {
		int position = stoi(input);
		return position >= 0 && position < expectedAnswers.size();
	}
	catch (...) {
		return false;
	}

}
string Player::RequestInput(string question)
{
	AllowInput();
	return GetPlayerInput();
}

int Player::RequestInput(string question, vector<string> expectedAnswers){
	string output = question.append("\n");
	for (int i = 0; i < expectedAnswers.size(); i++){
		output.append(" [");
		output.append(std::to_string(i));
		output.append("] ");
		output.append(expectedAnswers.at(i));
		output.append("\n");
	}
	
	string answer = "";
	do{
		Send(output);
		AllowInput();
		answer = GetPlayerInput();
	} while (!ValidateAnswer(answer, expectedAnswers));

	return stoi(answer);
}

string Player::GetPlayerInput()
{
	while (true) {
		ClientCommand command;
		SocketManager::getInstance().queue.get(command); // will block here unless there still are command objects in the queue
		shared_ptr<Socket> client{ command.get_client() };
		if (client) {
			try {
				if (command.getPlayer().get() == this){

					return command.get_cmd();
				}
				//PlayerInput.put(client.get()->get(), command.get_cmd());
			}
			catch (const exception& ex) {
				client->write("Sorry, ");
				client->write(ex.what());
				client->write("\n");
			}
			catch (...) {
				client->write("Sorry, something went wrong during handling of your request.\n");
			}
			//client->write(socketexample::prompt);
		}
		else {
			std::cerr << "trying to handle command for client who has disappeared...\n";
		}
	}

}

void Player::GiveGoldPieces(int amount) {
	m_GoldPieces += amount;
}

void Player::SetGoldPieces(int amount) {
	m_GoldPieces = amount;
}

int Player::GetGoldPieces() {
	return m_GoldPieces;
}

void Player::GiveGPForCards(CardColour colour) {

	int cardCount{ 0 };

	for (int i{ 0 }; i < GetCityCardContainer()->Size(); i++) {
		if (GetCityCardContainer()->At(i)->GetColour() == colour) {
			cardCount++;
		}
	}

	if (cardCount > 0) {
		Send("You have received additional goldpieces because of your cards! Bonus GP: " + std::to_string(cardCount));
		GiveGoldPieces(cardCount);

	}
}

Player::~Player()
{
}

