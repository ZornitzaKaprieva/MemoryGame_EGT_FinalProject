#include "Card.h"
#include "Game.h"

Card::Card(const char* faceTextureSheet, const char* backTextureSheet, std::string name, int x, int y, bool isFace)
{
	FaceTexture = TextureManager::loadTexture(faceTextureSheet); //to load the face texture
	BackTexture = TextureManager::loadTexture(backTextureSheet); //to load the back texture
	this->name = name;
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

bool Card::getIsFace()
{
	return this->isFace;
}

void Card::setName(std::string name)
{
	this->name = name;
}

std::string Card::getName()
{
	return this->name;
}

Card::~Card()
{
}