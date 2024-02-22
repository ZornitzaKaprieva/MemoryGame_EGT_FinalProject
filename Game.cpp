#include "Game.h"
#include "Board.h"
#include "Card.h"


SDL_Renderer* Game::renderer = nullptr; //define and initialize it to null because we haven't initialized sdl yet

Game::Game()
{
	Game::window = NULL;
	Game::renderer = NULL;
}

//initialize subsystems:
void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)  //in this case flags are fullscreen. Used as parameter in creating window
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) //check for errors before creating windows and renderers
	{
		std::cout << "Subsystems initialized.\n";

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags); //create a window 
		if (window != 0) //check window init success before creating renderers
		{
			std::cout << "Window created.\n";

			renderer = SDL_CreateRenderer(window, -1, 0); //create a renderer 
			if (renderer != 0) //check renderer init success
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);//set color:
				std::cout << "Renderer created\n";
			}
		}

		isRunning = true; // in main if
	}
	else
	{
		isRunning = false; // if there are errors while creating subsystems (window and renderer)
	}

	//each card is initialized in Board separately. Here we only initialize the board:
	board = new Board("assets/cards/jungle-01.jpg");
	std::cout << "Board created.\n";
}

void Game::handleEvents()
{
	

	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		std::cout << "QUIT event\n";
		isRunning = false;
		break;

		//TODO: 
		
	case SDL_MOUSEBUTTONDOWN: //by clicking with the mouse
		
	 board->mouseClicking();

	 break;

	default:
		break;
	}
}

void Game::update()
{
	board->update();
}

void Game::render() //Here we add a rendering board. Individual cards are rendered in class Board
{
	SDL_RenderClear(renderer);

	board->render();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Clean\n";
}

Game::~Game()
{
	std::cout << "Destructor\n";
}