#include "Board.h"
#include "Game.h"
#include <string>

Board::Board(const char* textureSheet)
{
	objTexture = TextureManager::loadTexture(textureSheet);


	//initialize each card that will be used:
	
	//TODO to replace with vector:
	foxG = new Card("assets/cards/foxGreen.png", "assets/cards/jungle.jpg", "foxG", 0, 0, true);
	lionB = new Card("assets/cards/lionBlue.png", "assets/cards/jungle.jpg","lionB", 200, 0, true);
	raccoonP = new Card("assets/cards/raccoonPink.png", "assets/cards/jungle.jpg","raccoonP", 400, 0, true);
	beaverR = new Card("assets/cards/beaverRed.png", "assets/cards/jungle.jpg","beaverR", 600, 0, true);
	skunkO = new Card("assets/cards/skunkOrange.png", "assets/cards/jungle.jpg","skunkO", 0, 200, true);
	hippoG = new Card("assets/cards/hippoGold.png", "assets/cards/jungle.jpg","hippoG", 200, 200, true);
	sealO = new Card("assets/cards/sealOrange.png", "assets/cards/jungle.jpg","sealO", 400, 200, true);
	catP = new Card("assets/cards/catPink.png", "assets/cards/jungle.jpg","catP", 600, 200, true);


	//to fill std::vector<Card*> deckOfCards:

	for (int i = 0; i < 4; i++) //4 columns
	{
		std::vector<Card*> newRow; //to create new vector for filling  4 rows
		deckOfCards.push_back(newRow); //to add a new row in each iteration
		for (int j = 0; j < 4; j++) //to add new card in each iteration (4x4)
		{
			//foxG = new Card("assets/cards/foxGreen.png", "assets/cards/jungle.jpg", "foxG", 0, 0, true);
			deckOfCards.back().push_back(foxG);
			deckOfCards.back().push_back(lionB);
			deckOfCards.back().push_back(raccoonP);
			deckOfCards.back().push_back(beaverR);
			

			/*deckOfCards.back().push_back(foxG);
			deckOfCards.back().push_back(lionB);
			deckOfCards.back().push_back(raccoonP);
			deckOfCards.back().push_back(beaverR);*/

		}
	}


}

//update card:
void Board::update()
{
	//srcRect.h = 800;
	//srcRect.w = 800;
	//srcRect.x = 0;
	//srcRect.y = 0;

	//destRect.x = 0;
	//destRect.y = 0;
	//destRect.w = srcRect.w;
	//destRect.h = srcRect.h;

	//SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

//render card:
void Board::render()
{

	//here and in update()
	srcRect.h = 800;
	srcRect.w = 800;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = 0;
	destRect.y = 0;
	destRect.w = srcRect.w; 
	destRect.h = srcRect.h;

	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	/*foxG->render();
	lionB->render();
	raccoonP->render();
	beaverR->render();*/

	for (unsigned int i = 0; i < deckOfCards.size(); i++)
	{
		for (unsigned int j = 0; i < deckOfCards.size(); i++) //deckOfCards[i].size() - 1
		{
			deckOfCards[0][0]->render();
			deckOfCards[0][1]->render();
			//deckOfCards[i][j]->render();
			// 
			//if (deckOfCards[i][j] == foxG)
				//foxG->render();

		}
	}
	
	//deckOfCards[0][0]->render(); //ok
	//deckOfCards[0][1]->render(); //
	//deckOfCards[0][2]->render(); //
	//deckOfCards[0][3]->render(); //


	
	
	/*skunkO->render();
	hippoG->render();
	sealO->render();
	catP->render();*/
}


//TODO:
//void Board::vectorRender(std::vector<std::vector<Card*>> deckOfCards) //vectorRender(deckOfCards);
//{
//	this->deckOfCards = deckOfCards;
//	for (unsigned int i = 0; i < deckOfCards.size(); i++) 
//	{
//		for (unsigned int j = 0; i < deckOfCards.size(); i++) //deckOfCards[i].size() - 1
//		{
//			deckOfCards[i][j]->render();
//			//if (deckOfCards[i][j] == foxG)
//				//foxG->render();
//			
//		}
//	}
//}

Board::~Board()
{
}