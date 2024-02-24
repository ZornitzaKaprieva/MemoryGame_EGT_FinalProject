
#pragma once

#include<string>
#include<vector>
#include "Card.h"
#include "Player.h"
#include "SoundManager.h"

class Board
{
public:
	Board() {}; //default constructor 
	Board(const char* textureSheet); //constructor with parameter texture

	~Board(); //destructor

	void update(); //to update an already created card
	void renderCard(); //specific behavior


	void cardsArrRender(); //to render from array

	void mouseClicking();

	void setPos(int x, int y);

	void loadAndPlaySound();



	bool running() { return isRunning; }

private:
	Card deckOfCards[4][4]; //array to put all the cards in one deck
	Player* player;
	//Player player;

	Card currentCard; //instead of std::string selectedCard;
	// std::string selectedCard; //to check if card1 and card2 are equal

	//new:
	int clickCount = 0;

	bool isFace; //bool for the constructor
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
	bool isRunning = false; //bool for main.cpp 

};