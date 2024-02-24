#pragma once
#include <string>
class Player
{
public:
	
	Player();
	Player(std::string playerName);
	void setPlayerName(std::string playerName);
	std::string getPlayerName();

	double getTimeToSolve();

	void addMistake();
	int getMistakes();

	void addMoves();
	int getMoves();

	void addPoints();
	int getPoints();

	void getFinalStatistics();

	~Player();
	
private:
	std::string playerName;
	double timeToSolve;
	int mistakes;
	int moves;
	int points;

};

