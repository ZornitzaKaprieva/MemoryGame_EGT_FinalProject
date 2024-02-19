#pragma once
#include <SDL.h>
#include <SDL_image.h> //png, jpeg, etc
#include "TextureManager.h"

class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void handleEvents();
	void update(); //to make all game objects updateable 
	void render(); //to load the picture
	void clean(); //to free memory 

	bool isRunning();
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	SDL_Texture* texture = NULL;
	SDL_Rect sourceRectangle; //the image itself
	SDL_Rect destinationRectangle;

	int currentFrame; // for movement through frames
};