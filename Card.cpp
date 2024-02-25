#include "Card.h"
#include "Game.h"

Card::Card(const char* faceTextureSheet, const char* backTextureSheet, std::string id, int x, int y, bool isFace)
{
	FaceTexture = TextureManager::loadTexture(faceTextureSheet); //to load the face texture
	BackTexture = TextureManager::loadTexture(backTextureSheet); //to load the back texture
	this->id = id;
	this->xpos = x;
	this->ypos = y;
	this->isFace = isFace;
}

//to load BackTexture
void Card::updateBack()
{
	srcRect.h = 200;
	srcRect.w = 200;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	SDL_RenderCopy(Game::renderer, BackTexture, &srcRect, &destRect);
}


//to load FaceTexture
void Card::updateFace()
{
	srcRect.h = 200;
	srcRect.w = 200;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	SDL_RenderCopy(Game::renderer, FaceTexture, &srcRect, &destRect);
}

void Card::setPos(int x, int y) //to be able to set the positions of each card
{
	xpos = x;
	ypos = y;
}

void Card::renderCard()
{
	if (isFace)
	{
		updateFace();
		//std::cout << "Render Face" << std::endl;	
	}
	else
	{
		updateBack();
		//std::cout << "Render Back" << std::endl;
	}
}


void Card::setIsFace(bool isFace)
{
	this->isFace = isFace;
}

//TODO: 
void Card::switchFaceBack()
{
	//todo ne razboti 6
	/*SDL_Event event2;

	SDL_PollEvent(&event2);

	event2.type = SDL_MOUSEBUTTONDOWN;

	std::cout << "event2.type = SDL_MOUSEBUTTONDOWN;" << std::endl;*/

	/*if (this->isFace = false)
		setIsFace(true);

	if (this->isFace = true)
		setIsFace(false);*/
}

bool Card::getIsFace()
{
	return this->isFace;
}

void Card::setID(std::string id)
{
	this->id = id;
}

std::string Card::getID()
{
	//std::cout << "ID\n";
	return this->id;
}

Card::~Card()
{
}