#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objTexture = TextureManager::loadTexture(textureSheet); //no need for ren

	xpos = x;
	ypos = y;
}


//update card:
void GameObject::updateObj()
{

	srcRect.h = 200; //32
	srcRect.w = 200; //32
	srcRect.x = 0; //0
	srcRect.y = 0; //0

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;// / 2; 
	destRect.h = srcRect.h;// / 2;

	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}

//render card:
void GameObject::renderObj()
{
			SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

//update back:
void GameObject::updateBack()
{

	srcRect.h = 800; //200 to load 1 img multiple times; 800 - to load 1 img 1 time
	srcRect.w = 800; //200
	srcRect.x = 0; //0
	srcRect.y = 0; //0

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;// / 2; 
	destRect.h = srcRect.h;// / 2;

	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}

//render back:
void GameObject::renderBack()
{

	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

	//to load img of 200 px multiple times:
	/*for (int i = 0; i < 4; i++)
	{


		for (int j = 0; j < 4; j++)
		{

			SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
			destRect.y += 200;

		}
		destRect.x += 200;
		destRect.y = 0;
	}*/
}
/// </summary>

GameObject::~GameObject()
{
}