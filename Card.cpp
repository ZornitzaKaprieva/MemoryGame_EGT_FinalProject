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

void Card::render()
{
	if (isFace)
	{
		updateFace();
		//setIsFace(!isFace); //TODO to implement in other function
	}
		
	else
	{
		updateBack();
		//setIsFace(isFace); //TODO to implement in other function
	}
		
}


void Card::setIsFace(bool isFace)
{
	this->isFace = isFace;
}

//TODO: 
void Card::switchFaceBack() //къде да я използвам?
{

	if (this->isFace = false)
		setIsFace(true);

	if (this->isFace = true)
		setIsFace(false);
}

bool Card::getIsFace()
{
	return this->isFace;
}

Card::~Card()
{
}

