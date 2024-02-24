#include "Player.h"

Player::Player()
{
	this->mistakes = 0;
	this->moves = 0;
	this->points = 0;
	this->playerName = "";
}

Player::Player(std::string playerName)
{
	this->mistakes = 0;
	this->moves = 0;
	this->points = 0;
	this->playerName = playerName;
}

void Player::setPlayerName(std::string playerName)
{
	this->playerName = playerName;
}

std::string Player::getPlayerName()
{
	return this->playerName;
}

void Player::addMistake()
{
	this-> mistakes++;

}

int Player::getMistakes()
{
	return this-> mistakes;
}



void Player::addMoves()
{
	this->moves++;
}

int Player::getMoves()
{
	return this->moves;
}

void Player::addPoints()
{
	this->points++;
}

int Player::getPoints()
{
	return this->points;
}

//void Player::getFinalStatistics()
//{
//	int finalMistkes;
//	int finalMoves;
//	int finalPoints;
//}


Player::~Player()
{
}