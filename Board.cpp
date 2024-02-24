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
	player = new Player("Zornitza"); //new
	
	
	//currentCard.setIsFace(false); //by default the back of the card is displayed;
	//currentCard.setID(""); //the name of the currentCard - an empty string by default

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

	SoundManager::Instance()->load("assets/sounds/win.wav", "win", 0); //0 = efects (switch in SaoundManager.cpp
	SoundManager::Instance()->load("assets/sounds/lose.wav", "lose", 0);
	SoundManager::Instance()->load("assets/sounds/gameLose.mp3", "gameLose", 1);
	SoundManager::Instance()->load("assets/sounds/gameOver.wav", "gameOver", 1);
}

//update card:
void Board::update()
{
	//helping logic
	//SDL_Delay(100); // wait for 0.1 second before continuing
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
	SDL_Event event1;
	SDL_PollEvent(&event1);
	event1.type = SDL_MOUSEBUTTONDOWN; //by clicking with the mouse

	int mx, my;
	int w = 800, h = 800;

	SDL_GetMouseState(&mx, &my); //mouse coordinates
	std::cout << "Coordinates: " << mx << " / " << my << std::endl;

	int indexX = mx / 200; //to open field - xpos (0, 1, 2, 3)
	int indexY = my / 200; //to open field - ypos (0, 1, 2, 3)

	bool twoCardsSelected = false;

	//TODO: to do if statement to close all the cards, is they don't matches;
	//TODO: not to be able to click on already opened cards
	//TODO: Is the game over? Is it a new record? Is it a loss? (add sound effects)

	//if-else statement to check if cards id matches inside if-else statement to check current card id:
	if (currentCard.getID() == "") //turn the card face up if id = empty string
	{

		currentCard.setID(deckOfCards[indexY][indexX].getID());//set the ID of the current playing card to be the same as the dealt playing card standing in the same field

		deckOfCards[indexY][indexX].setIsFace(true); // flip the playing card (face up)
		currentCard = deckOfCards[indexY][indexX]; // we assign the value of deckOfCards[indexY][indexX] to the currentCard

		std::cout << "Card1 : ";
		std::cout << deckOfCards[indexY][indexX].getID() << std::endl;
		std::cout << std::endl;
		twoCardsSelected = false;
	}
	else
	{
		//open a pair of cards: 
		deckOfCards[indexY][indexX].setIsFace(true); //if there is a match: the second card stays open
		currentCard.setIsFace(true); 
		player->addMoves(); //add new move (2 open cards = 1 move)
			
		//check for a match:
		if (currentCard.getID() == deckOfCards[indexY][indexX].getID()) //takes the ID of the current card and compares it to the ID of the second open card
		{
			std::cout << "current Card: " << currentCard.getID() << std::endl;
			std::cout << "Card2: " << deckOfCards[indexY][indexX].getID() << std::endl;

			//deckOfCards[indexY][indexX].setIsFace(true); //if there is a match: the second card stays open
			/*currentCard.setIsFace(true);*/

			std::cout << "WIN!" << std::endl;
			SoundManager::Instance()->playSound("win", 0, 0);
			
			currentCard.setID("");
			player->addPoints();
			
			//player->addMoves();
			std::cout << std::endl;
			twoCardsSelected = true;		
		}
		else
		{		
			// Display the second selected card:
			//deckOfCards[indexY][indexX].setIsFace(true);
			
			
			// Wait for 1 second before closing the cards
			// //SDL_Delay(1000); //1st option
			// //std::this_thread::sleep_for(1s); //2nd option
			
			
			//3rd option
			/*
			std::string waitString = "Waiting for 1 second...";
			std::cout << waitString << std::endl;
			uint32_t startTime = SDL_GetTicks();
			while (SDL_GetTicks() - startTime < 1000) 
			{
				deckOfCards[indexY][indexX].setIsFace(true);
				currentCard.setIsFace(false);
			}
			*/
			
			// Close the cards
			deckOfCards[indexY][indexX].setIsFace(false);
			currentCard.setIsFace(false); //did not work

			std::cout << "current Card: : " << currentCard.getID() << std::endl;
			std::cout << "Card2: " << deckOfCards[indexY][indexX].getID() << std::endl;
			std::cout << "You LOSE! " << std::endl;
			SoundManager::Instance()->playSound("lose", 0, 0);
			
			currentCard.setID("");
			twoCardsSelected = true; //new
			player->addMistake();
			std::cout << "Mistakes: " << player->getMistakes() << std::endl;
			std::cout << std::endl;
		}
	}

	std::cout << player->getPlayerName() << "'s current statistics: " << std::endl;
	std::cout << "Moves: " << player->getMoves() << std::endl;
	std::cout << "Points: " << player->getPoints() << std::endl;
	std::cout << "Screen size: " << w << " / " << h << " " << "Index x-y: " << indexX << " " << indexY << " " << currentCard.getID() << "\n";

	//Check result and moves (max moves = 20))
	if (player->getMoves() == 20) //TODO: with while and warp all code
	{
		SoundManager::Instance()->playMusic("gameLose", 0, 0); //ok
		//TODO: load cards again
	}
	else
	{
		SoundManager::Instance()->playSound("gameOver", 0, 0); //did not work
		//TODO: new record sound !
		//TODO: load cards again
	}

}

Board::~Board()
{
}