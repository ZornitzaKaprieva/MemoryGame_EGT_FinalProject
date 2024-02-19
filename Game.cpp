#include "Game.h"
#include <iostream>

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::sourceRectangle.x = Game::sourceRectangle.y = Game::sourceRectangle.w = Game::sourceRectangle.h = 0;
	Game::destinationRectangle.x = Game::destinationRectangle.y = Game::destinationRectangle.w = Game::destinationRectangle.h = 0;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { // if == 0 - succsessfuly initilized the SDL subsystem
		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);


				// loading texture using static TextureManager* Instance()
				TextureManager::Instance()->loadTexture("assets/cards/foxGreen.png", "foxGreen", renderer); //file, id, render
				TextureManager::Instance()->loadTexture("assets/cards/lionBlue.png", "lionBlue", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/raccoonPink.png", "raccoonPink", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/beaverRed.png", "beaverRed", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/skunkOrange.png", "skunkOrange", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/hippoGold.png", "hippoGold", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/sealOrange.png", "sealOrange", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/catPink.png", "catPink", renderer);
			}
			else {
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else {
			std::cout << "window init failed\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "init success\n";
	running = true;
	return true;
}

void Game::render() { //clear buffer
	SDL_RenderClear(renderer);
	//from TextureManager:
	//horizontal (4 cards)
	TextureManager::Instance()->drawTexture("foxGreen", 0, 0, 200, 200, renderer); //optional: SDL_FLIP_HORIZONTAL
	TextureManager::Instance()->drawTexture("lionBlue", 200, 0, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("raccoonPink", 400, 0, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("beaverRed", 600, 0, 200, 200, renderer);
	
	//vertical - col1 (3 cards)
	TextureManager::Instance()->drawTexture("foxGreen", 0, 200, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("lionBlue", 0, 400, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("catPink", 0, 600, 200, 200, renderer);
	//vertical - col2 (3 cards)
	TextureManager::Instance()->drawTexture("beaverRed", 200, 200, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("catPink", 200, 400, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("raccoonPink", 200, 600, 200, 200, renderer);
	//vertical - col3 (3 cards)
	TextureManager::Instance()->drawTexture("skunkOrange", 400, 200, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("sealOrange", 400, 400, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("hippoGold", 400, 600, 200, 200, renderer);
	//vertical - col4 (3 cards)
	TextureManager::Instance()->drawTexture("skunkOrange", 600, 200, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("sealOrange", 600, 400, 200, 200, renderer);
	TextureManager::Instance()->drawTexture("hippoGold", 600, 600, 200, 200, renderer);

	
	SDL_RenderPresent(renderer);

}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false; break; //by clicking x on the window
		default: break;
		}
	}
}

void Game::update()
{
}
void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return Game::running;
}

Game::~Game() {
}