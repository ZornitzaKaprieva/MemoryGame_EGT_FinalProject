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
	Card foxG("assets/cards/foxGreen.png", "assets/cards/jungle.png", "foxG", 0, 0, false);
	Card lionB("assets/cards/lionBlue.png", "assets/cards/jungle.png", "lionB", 0, 0, false);
	Card raccoonP("assets/cards/raccoonPink.png", "assets/cards/jungle.png", "raccoonP", 0, 0, false);
	Card beaverR("assets/cards/beaverRed.png", "assets/cards/jungle.png", "beaverR", 0, 0, false);
	Card skunkO("assets/cards/skunkOrange.png", "assets/cards/jungle.png", "skunkO", 0, 0, false);
	Card hippoG("assets/cards/hippoGold.png", "assets/cards/jungle.png", "hippoG", 0, 0, false);
	Card sealO("assets/cards/sealOrange.png", "assets/cards/jungle.png", "sealO", 0, 0, false);
	Card catP("assets/cards/catPink.png", "assets/cards/jungle.png", "catP", 0, 0, false);

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

	//instead of 
	//selectedCard = ""; // the selected card as an empty string so it can take the value of the first open card and compare it to the second
	//Card currentCard("assets/cards/cc.png", "assets/cards/jungle.jpg", "", 0, 0, false);
	player = new Player("Zornitza"); //new
	currentCard.setIsFace(false); //by default the back of the card is displayed;
	currentCard.setName(""); //the name of the currentCard - an empty string by default
	

	srand(time(0)); //to randomize the card order for each new game

	//principle that randomizes the cards:
	for (int i = 0; i < 4; i++) { //4 columns
		for (int j = 0; j < 4; j++) { //4 rows
			int randomIndex = rand() % 4; //numbers are random from 0 to 3 but can be repeated because of i and j
			Card temp = deckOfCards[i][j]; //temporary card object to hold the value 
			deckOfCards[i][j] = deckOfCards[randomIndex][randomIndex]; // to swap current card with another random card
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
	//SoundManager::Instance()->load("assets/sounds/gameLose.mp3", "gameLose", 1);
	SoundManager::Instance()->load("assets/sounds/gameOver.wav", "gameOver", 0);	
	//SoundManager::Instance()->load("assets/sounds/newRecord.mp3", "newRecord", 1);
	
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

	//currentCard.renderCard(); ////////
}

void Board::cardsArrRender()
{
	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			//deckOfCards[i][j].getID();
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

	bool twoCardsSelected = false; //todo

	//TODO: to do if statement to close all the cards, if they don't matches;
	//TODO: not to be able to click on already opened cards (if currentCard.getName() == "" is clickable
	//TODO: checks: Is the game over? Is it a new record? Is it a loss? 
	
	/*int tempIndexY = 0;
	int tempIndexX = 0;*/

	//if-else statement to check if cards id matches inside if-else statement to check current card id:
	if (currentCard.getName() == "" ) //turn the card face up if id = empty string
	{
		//assign name, position, bool:
		currentCard.setName(deckOfCards[indexY][indexX].getName());//set the name of the current playing card to be the same as the dealt playing card standing in the same field
		currentCard.setPos(deckOfCards[indexY][indexX].getYpos(), deckOfCards[indexY][indexX].getXpos());
		
		deckOfCards[indexY][indexX].setIsFace(true); // flip the playing card (face up)
		currentCard.setIsFace(deckOfCards[indexY][indexX].getIsFace());

		//Card tempCard(deckOfCards[indexY][indexX].getFaceTexture(), "assets/cards/jungle.png", deckOfCards[indexY][indexX].getName(), indexY, indexY, false);
		/*tempIndexY = deckOfCards[indexY][indexX].getYpos();
		tempIndexX = deckOfCards[indexY][indexX].getXpos();*/

		std::cout << "Card1 : ";
		std::cout << deckOfCards[indexY][indexX].getName() << std::endl;
		std::cout << std::endl;
		twoCardsSelected = false;
	}
	else
	{	
		player->addMoves(); //add new move (2 open cards = 1 move)
		
		//check for a match:
		if (currentCard.getName() == deckOfCards[indexY][indexX].getName()) //takes the ID of the current card and compares it to the ID of the second open card
		{	
			std::cout << "current Card: " << currentCard.getName() << std::endl;
			std::cout << "Card2: " << deckOfCards[indexY][indexX].getName() << std::endl;

			//open a pair of cards if there is a match:
			deckOfCards[indexY][indexX].setIsFace(true); //if there is a match: the second card stays open
			deckOfCards[currentCard.getYpos()][currentCard.getXpos()].setIsFace(true); //if there is a match: the first card stays open

			std::cout << "WIN!" << std::endl;
			std::cout << "CARD 2 WIN POS: Y: " << deckOfCards[indexY][indexX].getYpos() << "  X: " << deckOfCards[indexY][indexX].getXpos() << std::endl;
			std::cout << std::endl;

			SoundManager::Instance()->playSound("win", 0, 0);

			currentCard.setName("");
			player->addPoints();
			twoCardsSelected = true;
		}
		else
		{
			isMatching = false;
		
			// Display the second selected card:
			//deckOfCards[indexY][indexX].setIsFace(true);

			// Close the cards (with void Board::matching(bool isMatching))
			
			// Wait for 1 second before closing the cards
			// //SDL_Delay(1000); //1st option
			// //std::this_thread::sleep_for(1s); //2nd option

			deckOfCards[indexY][indexX].setIsFace(false);
			deckOfCards[currentCard.getYpos()][currentCard.getXpos()].setIsFace(false);  //TODO (for now: only closes the card at position 0 0)
			currentCard.setName("");

			std::cout << "current Card: : " << currentCard.getName() << std::endl;
			std::cout << "Card2: " << deckOfCards[indexY][indexX].getName() << std::endl;
			std::cout << "You LOSE! " << std::endl;
			SoundManager::Instance()->playSound("lose", 0, 0);
		
			twoCardsSelected = true; //new
			player->addMistake();
			std::cout << "Mistakes: " << player->getMistakes() << std::endl;
			std::cout << std::endl;
		}
	}

	std::cout << player->getPlayerName() << "'s current statistics: " << std::endl;
	std::cout << "Moves: " << player->getMoves() << std::endl;
	std::cout << "Points: " << player->getPoints() << std::endl;
	std::cout << "Screen size: " << w << " / " << h << " " << "Index x-y: " << indexX << " " << indexY << " " << currentCard.getName() << "\n";

	//TODO:
	bool isAllCardsOpened =
		deckOfCards[0][0].getIsFace() == true &&
		deckOfCards[0][1].getIsFace() == true &&
		deckOfCards[0][2].getIsFace() == true &&
		deckOfCards[0][3].getIsFace() == true &&

		deckOfCards[1][0].getIsFace() == true &&
		deckOfCards[1][1].getIsFace() == true &&
		deckOfCards[1][2].getIsFace() == true &&
		deckOfCards[1][3].getIsFace() == true &&

		deckOfCards[2][0].getIsFace() == true &&
		deckOfCards[2][1].getIsFace() == true &&
		deckOfCards[2][2].getIsFace() == true &&
		deckOfCards[2][3].getIsFace() == true &&

		deckOfCards[3][0].getIsFace() == true &&
		deckOfCards[3][1].getIsFace() == true &&
		deckOfCards[3][2].getIsFace() == true &&
		deckOfCards[3][3].getIsFace() == true;

	//Check result and moves (max moves = 20))
	if (player->getMoves() == 20 && !isAllCardsOpened) //TODO: to end a game 
	{
		SoundManager::Instance()->playMusic("gameLose", 0, 0); //ok
		//TODO: load cards again
	}
	else
	{
		//SoundManager::Instance()->playSound("gameOver", 0, 0); //did not work
		//TODO: new record sound !
		//TODO: load cards again
	}
}

//new (for face up cards and flipping mismatched cards): to call in update
//void Board::matching(bool isMatching)
//{
//	Card card;
//	if (isMatching == false)
//	{
//		SDL_Delay(1000);
//		card.setIsFace(false);
//	}
//}

Board::~Board()
{
}
