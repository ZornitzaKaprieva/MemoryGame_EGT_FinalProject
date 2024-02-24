#include "Board.h"
#include "Game.h"
#include <string>
#include <algorithm> //for randomize 
#include<cstdlib> //for randomize 
#include<chrono> //for delay
#include<thread> //for delay
#include<ctime> //for delay
using namespace std::chrono;

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

	//instead of selectedCard = ""; // the selected card as an empty string so it can take the value of the first open card and compare it to the second
	
	Card currentCard("assets/cards/cc.png", "assets/cards/jungle.jpg", "", 0, 0, false);
	//currentCard.setIsFace(false); //by default the back of the card is displayed;
	//currentCard.setID(""); //the name of the currentcard - an empty string by default
	

	srand(time(0)); //to randomize the card order for each new game
	 
	//principle that randomizes the cards:
	for (int i = 0; i < 4; i++) { //4 columns
		for (int j = 0; j < 4; j++) { //4 rows
			int randomIndex = rand() % 4; //numbers are random from 0 to 3 but can be repeated because of i and j
			Card temp = deckOfCards[i][j]; //temporary card object to hold the value 
			deckOfCards[i][j] = deckOfCards[randomIndex][randomIndex]; //
			deckOfCards[randomIndex][randomIndex] = temp; //
		}
	}

	//to set a position in the cards of the deckOfCards:
	for (int i = 0; i < 4; i++) //4 columns
	{
		for (int j = 0; j < 4; j++) //to set card position in each iteration (4x4)
		{
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

	for (unsigned int i = 0; i < 4; i++) 
	{
		for (unsigned int j = 0; j < 4; j++) 
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

	/*if (event1.type = SDL_MOUSEBUTTONDOWN)
	{*/
	
	event1.type = SDL_MOUSEBUTTONDOWN; //by clicking with the mouse

	int mx, my;
	int w = 800, h = 800;

	SDL_GetMouseState(&mx, &my); //mouse coordinates
	std::cout << "Coordinates: " << mx << " / " << my << std::endl;

	int indexX = mx / 200; //to open field 
	int indexY = my / 200;

	//TODO: to do if statement to close all the cards, is they dont matches;

	//if-else statement to check if cards id matches inside if-else statement to check current card id:
	if (currentCard.getID() == "") //turn the card face up if id = empty string
	{
		currentCard.setID(deckOfCards[indexY][indexX].getID());//set the ID of the current playing card to be the same as the dealt playing card standing in the same field
		
		deckOfCards[indexY][indexX].setIsFace(true); // flip the playing card (face up)
		std::cout << "Card1 : ";
		std::cout << deckOfCards[indexY][indexX].getID() << std::endl; 
	}
	else
	{	
		if (currentCard.getID() == deckOfCards[indexY][indexX].getID()) //takes the ID of the current card and compares it to the ID of the second open card
		{
			std::cout << "Card2: " << deckOfCards[indexY][indexX].getID() << std::endl;
			
			deckOfCards[indexY][indexX].setIsFace(true); //if there is a match: the second card stays open
			
			std::cout << "WIN!" << std::endl;
			std::cout << std::endl;
			currentCard.setID("");
		}
		else
		{
				deckOfCards[indexY][indexX].setIsFace(true); //to display the second selected card
				//TODO Delay:
				deckOfCards[indexY][indexX].setIsFace(false); //to hide the second selected card
				//not working: //currentCard.setIsFace(deckOfCards[indexY][indexX].getIsFace()); //NEW
		
			//auto one_second = 1s;
			//std::this_thread::sleep_for(one_second);
			//std::this_thread::sleep_for(std::chrono::seconds(1));
			
			//TODO: to close the flipped current card back before opening a new pair
			//not working:// selectedCard = deckOfCards[indexY][indexX].setIsFace(false);
			//not working: currentCard.setIsFace(false);

			std::cout << "Card2: " << deckOfCards[indexY][indexX].getID() << std::endl;
			std::cout << "You LOSE! " << std::endl;
			std::cout << std::endl;
			currentCard.setID("");
			
		}
	}
	std::cout << "Screen size: " << w << " / " << h << " " << "Index x-y: " << indexX << " " << indexY << currentCard.getID() << "\n";
}
//}


Board::~Board()
{
}