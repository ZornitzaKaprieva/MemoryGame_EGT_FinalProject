#include "Board.h"
//#include "Menu.h"
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

	//Card currentCard("assets/cards/cc.png", "assets/cards/jungle.jpg", "", 0, 0, false);
	player = new Player("Zornitza"); //new
	currentCard.setIsFace(false); //by default the back of the card is displayed;
	currentCard.setName(""); //the name of the currentCard - an empty string by default

	//menu
	//Menu menu("assets/cards/jungle.png", "foxG", 0, 0, false); //initialization for the menu board (26.02)

	srand(time(0)); //to randomize the card order for each new game

	//principle that randomizes the cards:
	for (int i = 0; i < 4; i++) { //4 columns
		for (int j = 0; j < 4; j++) { //4 rows
			int randomIndex = rand() % 4; //numbers are random from 0 to 3 but can be repeated because of i and j
			Card temp = deckOfCards[i][j]; //temporary card object to hold the value 
			deckOfCards[i][j] = deckOfCards[randomIndex][randomIndex]; // to swap current card with another random card
			deckOfCards[randomIndex][randomIndex] = temp; //to swap the current card with the randomly selected card.
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


	SoundManager::Instance()->load("assets/sounds/win.wav", "win", 0); //0 = effects (switch in SoundManager.cpp)
	SoundManager::Instance()->load("assets/sounds/lose.wav", "lose", 0);
	//SoundManager::Instance()->load("assets/sounds/gameLose.mp3", "gameLose", 1);
	SoundManager::Instance()->load("assets/sounds/gameOver.wav", "gameOver", 0);
	//SoundManager::Instance()->load("assets/sounds/newRecord.mp3", "newRecord", 1);
}

//update card:
void Board::update()
{
	//helping logic

	//crash // closeCards(deckOfCards[yposCardOfDeck][xposCardOfDeck]);
	//crash // matching(deckOfCards[yposCardOfDeck][xposCardOfDeck].getName());

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
	//TODO: checks: Is the game over? Is it a new record? Is it a loss? 

	//if-else statement to check if cards id matches inside if-else statement to check current card id:
	//TODO: && deckOfCards[indexY][indexX].getIsFace() == false

	if (deckOfCards[indexY][indexX].getIsFace() == false) // not to be able to click on already opened cards (if currentCard.getName() == "" is clickable
	{
		if (currentCard.getName() == "") //turn the card face up if id = empty string
		{
			//TEST: check position
			std::cout << "Pos Current card without assignment: " << currentCard.getYpos() << " : " << currentCard.getXpos() << std::endl;

			//assign name and position
			currentCard.setName(deckOfCards[indexY][indexX].getName());//set the name of the current playing card to be the same as the dealt playing card standing in the same field
			currentCard.setPos(deckOfCards[indexY][indexX].getYpos(), deckOfCards[indexY][indexX].getXpos());

			// flip the playing card (face up) and assign bool for face
			deckOfCards[indexY][indexX].setIsFace(true);
			currentCard.setIsFace(deckOfCards[indexY][indexX].getIsFace());

			//TEST: check positions: 
			std::cout << "Card1 : ";
			std::cout << deckOfCards[indexY][indexX].getName() << std::endl;
			std::cout << std::endl;
			std::cout << "1st if: deckOfCards Y: " << deckOfCards[indexY][indexX].getYpos() << " X: " << deckOfCards[indexY][indexX].getXpos() << std::endl;
			std::cout << "1st if: Current card  - Y: " << currentCard.getYpos() << " X: " << currentCard.getXpos() << std::endl;
			yposCurrentCard = currentCard.getYpos();
			xposCurrentCard = currentCard.getXpos();
			std::cout << "1st if: posCurrentCard  - Ypos: " << yposCurrentCard << " Xpos: " << xposCurrentCard << std::endl;
			twoCardsSelected = false; //is not used
		}
		else
		{
			player->addMoves(); //add new move (2 open cards = 1 move)

			//check for a match:
			if (currentCard.getName() == deckOfCards[indexY][indexX].getName()) //takes the ID of the current card and compares it to the ID of the second open card
			{
				std::cout << "currentCard Name: " << currentCard.getName() << std::endl;
				std::cout << "Card2 (deckOfCards) Name: " << deckOfCards[indexY][indexX].getName() << std::endl;

				currentCard.setPos(deckOfCards[indexY][indexX].getYpos(), deckOfCards[indexY][indexX].getXpos()); // set xpos i ypos for currentCard
				currentCard.setIsFace(true); //don`t know if is forking

				deckOfCards[indexY][indexX].setIsFace(true); //if there is a match: the second card stays open

				std::cout << "WIN!" << std::endl;
				std::cout << "CARD 2 (deckOfCards) WIN POS: Y: " << deckOfCards[indexY][indexX].getYpos() << "  X: " << deckOfCards[indexY][indexX].getXpos() << std::endl;
				std::cout << std::endl;

				SoundManager::Instance()->playSound("win", 0, 0);

				currentCard.setName("");
				player->addPoints();

				//TEST: check positions: 
				std::cout << "1st else - 2nd if: deckOfCards Y: " << deckOfCards[indexY][indexX].getYpos() << " X: " << deckOfCards[indexY][indexX].getXpos() << std::endl;
				std::cout << "1st else - 2nd if: Current card  - Y: " << currentCard.getYpos() << " X: " << currentCard.getXpos() << std::endl;
				std::cout << "1st else: posCurrentCard  - Ypos: " << yposCurrentCard << " Xpos: " << xposCurrentCard << std::endl;
				twoCardsSelected = true; //is not used
			}
			else
			{

				// Display /Hide the second selected card:
				deckOfCards[indexY][indexX].setIsFace(false);
				/*SDL_Delay(1000); //did not work
				deckOfCards[indexY][indexX].setIsFace(false); *///TODO: Wait for 1 second before closing the cards: //SDL_Delay(1000); OR //std::this_thread::sleep_for(1s); 

				//prep for void Board::update() -> crash:
				xposCardOfDeck = deckOfCards[indexY][indexX].getXpos();
				yposCardOfDeck = deckOfCards[indexY][indexX].getYpos();
				std::cout << "y/xposCardOfDeck = deckOfCards[indexY][indexX].getY/Xpos(): Y: " << deckOfCards[indexY][indexX].getYpos() << " X:" << deckOfCards[indexY][indexX].getXpos() << std::endl;

				// Close the cards (with bool Board::matching(bool isMatching))
				//matching(currentCard.getName()); //did not work
				//matching(deckOfCards[indexY][indexX].getName()); //did not work

				// Close the cards (closeCard(Card card))
				//closeCard(deckOfCards[indexY][indexX]); //did not work

				std::cout << "current Card: : " << currentCard.getName() << std::endl;
				std::cout << "Card2 (deckOfCards): " << deckOfCards[indexY][indexX].getName() << std::endl;

				//ok, but now I should close them: 
				std::cout << "1st else - 2nd else: deckOfCards Y: " << deckOfCards[indexY][indexX].getYpos() << " X: " << deckOfCards[indexY][indexX].getXpos() << std::endl;
				std::cout << "1st else - 2nd else: Current card  - Y: " << currentCard.getYpos() << " X: " << currentCard.getXpos() << std::endl;

				//to close 1st card:
				int newYpos = currentCard.getYpos() / 200;
				int newXpos = currentCard.getXpos() / 200;
				std::cout << "1st else - 2nd else: newYpos: " << newYpos << " newXpos: " << newXpos << std::endl;
				deckOfCards[newXpos][newYpos].setIsFace(false); // switch positions X and Y
				std::cout << "NEW: deckOfCards[newXpos][newYpos] Y: " << deckOfCards[newXpos][newYpos].getYpos() << " X: " << deckOfCards[newXpos][newYpos].getXpos() << std::endl;

				std::cout << "You LOSE! " << std::endl;
				currentCard.setName("");
				SoundManager::Instance()->playSound("lose", 0, 0);

				player->addMistake();
				std::cout << "Mistakes: " << player->getMistakes() << std::endl;
				std::cout << std::endl;
				twoCardsSelected = true; //is not used
			}
		}

		std::cout << std::endl;
		std::cout << player->getPlayerName() << "'s current statistics: " << std::endl;
		std::cout << "Moves: " << player->getMoves() << std::endl;
		std::cout << "Points: " << player->getPoints() << std::endl;
		std::cout << "Screen size: " << w << " / " << h << " " << "Index x-y: " << indexX << " " << indexY << " " << currentCard.getName() << "\n";
		std::cout << std::endl;
		
		 this->isAllCardsOpened =
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
		if (player->getMoves() == 5) // && !this->isAllCardsOpened) //TODO: to end a game 
		{
			SoundManager::Instance()->playMusic("gameLose", 0, 0); //did not work gameLose
			//TODO: load cards again
		}
		else if (this->isAllCardsOpened) //ok 
		{
			SoundManager::Instance()->playSound("gameOver", 0, 0); //did not work
			//TODO: new record sound !
			//TODO: load cards again
		}
	}
}

void Board::matching(std::string name1)
{
	if (name1 != deckOfCards[yposCardOfDeck][xposCardOfDeck].getName())
	{

		//deckOfCards[yposCurrentCard][xposCurrentCard].setIsFace(false); //crash
		SDL_Delay(1000);
		deckOfCards[yposCardOfDeck][xposCardOfDeck].setIsFace(false); //open pos 0 0 

		std::cout << "void Board::matching(bool isMatching)" << std::endl;
	}
}

void Board::closeCard(Card card)
{
	SDL_Delay(1000);
	card.setIsFace(false);
}

Board::~Board()
{
}
