#pragma once

#include<string>
#include<vector>
#include "Card.h"

class Board
{
public:
	Board() {};
	Board(const char* textureSheet);

	//TODO:
	//void mouseClicking(); //modified from Game.cpp:
	//no need for SDL_Renderer* ren
	~Board();

	void update(); //to update an already created card
	void renderCard(); //specific behavior

	//to render from vector
	void vectorRender(std::vector<std::vector<Card*> >deckOfCards);

	void mouseClicking();

	
	
	bool running() { return isRunning; }
	//TODO: (from DeckOfCards)
	//void shuffle(); // shuffles cards in deck
	//void deal(); // deals shuffled cards

private:


	bool isRunning = false;
	//initialize each card individually:
	Card* foxG; 
	Card* lionB;
	Card* raccoonP;
	Card* beaverR;
	Card* skunkO;
	Card* hippoG;
	Card* sealO;
	Card* catP;

	//vector of vectors (arr[][]-like)
	std::vector<std::vector<Card*> >deckOfCards; 

	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

	//bool for the constructor:
	bool isFace;

	

};