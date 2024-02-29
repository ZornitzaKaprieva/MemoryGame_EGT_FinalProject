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

	void matching(bool isMatching); //TODO to display for a while mismatching cards

	void closeCard(Card card);

	bool running() { return isRunning; }

private:
	Card deckOfCards[4][4]; //array to put all the cards in one deck
	Player* player; //Player player;
	//Menu* menu; //initialization for the menu board (26.02)

	Card currentCard; //instead of std::string selectedCard; //to check if card1 and card2 are equal

	int clickCount = 0;
	bool isMatching;// = false;// = true;//  false calls void matching(bool isMatching) multiple times via update, event handling does not work;
	bool isFace; //bool for the constructor
	int xpos;
	int ypos;

	//to store xpos and ypos on both cards
	int xposCurrentCard = 0;
	int yposCurrentCard = 0;
	int xposCardOfDeck = 0; // = 0;
	int yposCardOfDeck = 0; // = 0;

	bool isAllCardsOpened; //for end the game

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
	bool isRunning = false; //bool for main.cpp 

};
