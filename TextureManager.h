#pragma once
#include "Game.h"
#include <string>
#include <map>

class TextureManager {
public:
	static SDL_Texture* loadTexture(const char* fileName); //this function will return the texture we set (no need to initialize ren (SDL_Renderer* ren)

private:
	//for flip//todo
};