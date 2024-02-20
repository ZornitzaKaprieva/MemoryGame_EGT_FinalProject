﻿#pragma once

#include<SDL.h>
#include <SDL_image.h> 
#include <iostream>
#include <vector>
#include"GameObject.h"
#include"GameLogic.h"

class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int width, int height, bool fullscreen);
	void handleEvents();
	void update(); //to make all game objects updateable 
	void render(); //to load a visualization 
	void clean(); //to free memory 

	bool running() { return isRunning; }

	static SDL_Renderer* renderer; //instead of copying the render for each object

private:
	bool isRunning = false;
	SDL_Window* window;
	//SDL_Renderer* renderer; //no need because of static SDL_Renderer* renderer;
	
	//? std::vector<GameObject*> gameObjects;
};
