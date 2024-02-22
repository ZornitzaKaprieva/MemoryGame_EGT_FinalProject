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



	for (int i = 0; i < 4; i++)
	{
		//std::vector<Card*> newRow;
		////1sr vector : //push vector
		//Cards.push_back(newRow);
		//for (int j = 0; j < 4; j++)
		//{
		//	foxG = new Card("assets/cards/foxGreen.png", "assets/cards/jungle.jpg", "foxG", 0, 0, true);
		//	Cards.back().push_back(foxG);
		//}
	}


}

//update card:
void Board::update()
{
}

//render card:
void Board::render()
{
	srcRect.h = 800;
	srcRect.w = 800;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = 0;
	destRect.y = 0;
	destRect.w = srcRect.w; 
	destRect.h = srcRect.h;

	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	foxG->render();
	lionB->render();
	raccoonP->render();
	beaverR->render();
	skunkO->render();
	hippoG->render();
	sealO->render();
	catP->render();
}

Board::~Board()
{
}