#pragma once

#include<SDL.h>
#include <SDL_image.h> 
#include <iostream>
#include <vector>

#include"Board.h"

class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int width, int height, bool fullscreen);
	void handleEvents();
	void update(); //Here we add the rendered board. Individual cards are rendered in class Board
	void renderCard(); //to load a visualization 
	void clean(); //to free memory 

	bool running() { return isRunning; }

	static SDL_Renderer* renderer; //instead of copying the render for each object

private:
	bool isRunning = false;
	SDL_Window* window;
	Board* board; //separate initialization for each board

	//SDL_Renderer* renderer; //no need because of static SDL_Renderer* renderer;
};