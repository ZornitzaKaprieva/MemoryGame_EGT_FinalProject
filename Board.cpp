#include "Board.h"
#include "Game.h"
#include <string>
#include <algorithm> //for randomize 
#include<cstdlib> //for randomize 

Board::Board(const char* textureSheet)
{
	objTexture = TextureManager::loadTexture(textureSheet);

	//initialize each card that will be used:
	Card foxG("assets/cards/foxGreen.png", "assets/cards/jungle.jpg", "foxG", 0, 0, false);
	Card lionB("assets/cards/lionBlue.png", "assets/cards/jungle.jpg", "lionB", 0, 0, false);
	Card raccoonP("assets/cards/raccoonPink.png", "assets/cards/jungle.jpg", "raccoonP", 0, 0, false);
	Card beaverR("assets/cards/beaverRed.png", "assets/cards/jungle.jpg", "beaverR", 0, 0, false);
	Card skunkO("assets/cards/skunkOrange.png", "assets/cards/jungle.jpg", "skunkO", 0, 0, false);
	Card hippoG("assets/cards/hippoGold.png", "assets/cards/jungle.jpg", "hippoG", 0, 0, false);
	Card sealO("assets/cards/sealOrange.png", "assets/cards/jungle.jpg", "sealO", 0, 0, false);
	Card catP("assets/cards/catPink.png", "assets/cards/jungle.jpg", "catP", 0, 0, false);

	deckOfCards[0][0] = foxG;
	deckOfCards[0][1] = lionB;
	deckOfCards[0][2] = raccoonP;
	deckOfCards[0][3] = beaverR;

	deckOfCards[1][0] = skunkO;
	deckOfCards[1][1] = hippoG;
	deckOfCards[1][2] = sealO;
	deckOfCards[1][3] = catP;

	deckOfCards[2][0] = foxG;
	deckOfCards[2][1] = lionB;
	deckOfCards[2][2] = raccoonP;
	deckOfCards[2][3] = beaverR;

	deckOfCards[3][0] = skunkO;
	deckOfCards[3][1] = hippoG;
	deckOfCards[3][2] = sealO;
	deckOfCards[3][3] = catP;

	selectedCard = ""; // the selected card as an empty string so it can take the value of the first open card and compare it to the second

	srand(time(0)); //to randomize the card order for each new game

	// TODO:
	//+ да се финализира функцията в initBoard: затваря всички карти и разбърква с ранд (от 0  до 4 с модулно деление)
	// (трябва да се разбъркат определен брой пъти, да се изтеглят индекси за 2 кутийки и после да се разменят
	// връщаме с ранда случайна число - мястото й засега е в конструктора, после ще се променя  


	//NEW: to set a position in the cards of the deckOfCards: //win - lose is not corrrect 
	 
	//principle that randomizes the cards
	for (int i = 0; i < 4; i++) { //4 columns
		for (int j = 0; j < 4; j++) { //4 rows
			int randomIndex = rand() % 4; //numbers are random from 0 to 3 but can be repeated because of i and j
			Card temp = deckOfCards[i][j]; //temporary card object to hold the value 
			deckOfCards[i][j] = deckOfCards[randomIndex][randomIndex];
			deckOfCards[randomIndex][randomIndex] = temp;
		}
	}

	//to set a position in the cards of the deckOfCards:
	for (int i = 0; i < 4; i++) //4 columns
	{
		for (int j = 0; j < 4; j++) //to set card position in each iteration (4x4)
		{
			//deckOfCards[randomIndexI][randomIndexY].setPos(j * 200, i * 200);
			deckOfCards[i][j].setPos(j * 200, i * 200);
		}
	}
}


//update card:
void Board::update()
{
	//helping logic
}

//render card:
void Board::renderCard()
{
	//here instead in update()
	srcRect.h = 800;
	srcRect.w = 800;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = 0;
	destRect.y = 0;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	//foxG->render(); //ok
	//deckOfCards[0][0]->render(); //ok

	cardsArrRender(); //ok
}

void Board::cardsArrRender()
{

	for (unsigned int i = 0; i < 4; i++)  // deckOfCards.size()
	{
		for (unsigned int j = 0; j < 4; j++) //deckOfCards[i].size() 
		{
			deckOfCards[i][j].getID();
			deckOfCards[i][j].renderCard();
		}
	}
}

void Board::mouseClicking()
{

	//from Game.cpp
	SDL_Event event1;
	SDL_PollEvent(&event1);

	event1.type = SDL_MOUSEBUTTONDOWN; //by clicking with the mouse

	int mx, my;
	int w = 800, h = 800;

	SDL_GetMouseState(&mx, &my); //mouse coordinates
	std::cout << "Coordinates: " << mx << " / " << my << std::endl;

	int indexX = mx / 200;
	int indexY = my / 200;

	//ako select 
	// броиш с дилей 1 сек

	if (selectedCard.empty())
	{
		std::cout << "card1" << std::endl;
		selectedCard = deckOfCards[indexY][indexX].getID();
		deckOfCards[indexY][indexX].setIsFace(true);
		std::cout << deckOfCards[indexY][indexX].getID() << std::endl;

	}
	else
	{
		std::cout << "card2" << std::endl;
		// towa se ograjda w otdelen if
		if (selectedCard == deckOfCards[indexY][indexX].getID())
		{
			//deckOfCards[indexY][indexX].setIsFace(true); //witout delay
			//open card
			deckOfCards[indexY][indexX].setIsFace(true);
			
			std::cout << "win: " << deckOfCards[indexY][indexX].getID() << std::endl;
		}
		else
		{
			//close: //deckOfCards[indexY][indexX].setIsFace(true); //with delay 
			//затваряме предходната карта, отваряме нова карта 
			deckOfCards[indexY][indexX].setIsFace(false); //ok but tо turn to false the default possition 
			//TODO да се затваря първоначално обърнатата карта: 
			// selectedCard = deckOfCards[indexY][indexX].setIsFace(false);
			 selectedCard = "";
		
			std::cout << "lose: " << deckOfCards[indexY][indexX].getID() << std::endl;

		}
		selectedCard = "";
	}

	std::cout << "Screen size: " << w << " / " << h << " " << "Index x-y: " << indexX << " " << indexY << selectedCard << "\n";
}


Board::~Board()
{
}