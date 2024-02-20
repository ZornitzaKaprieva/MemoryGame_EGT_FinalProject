#include "TextureManager.h"
#include "GameObject.h"

//implement LoadTexture structure:
SDL_Texture* TextureManager::loadTexture(const char* fileName)
{
    //generate the texture: 
    SDL_Surface* tempSurface = IMG_Load(fileName);
    //create the texture: 
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface); //instead ren 
    //clear the surface: 
    SDL_FreeSurface(tempSurface);

   
    return tex; //return the texture 
    
}

void TextureManager::drawTexture(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

