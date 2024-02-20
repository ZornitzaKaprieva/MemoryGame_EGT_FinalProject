#include "Game.h"
//#include "TextureManager.h"
#include "GameObject.h"
//#include "DeckOfCards.h"
//#include "GameLogic.h"
#include <vector>

//card objects:
GameObject* cardBack;
GameObject* card1;
GameObject* card2;
GameObject* card3;
GameObject* card4;
GameObject* card5;
GameObject* card6;
GameObject* card7;
GameObject* card8;

/// <game logic: vector with cards>
std::vector<GameObject*> gameObjectsList;
static void addGameObject(GameObject* gameObject)
{
	gameObjectsList.push_back(gameObject);
}
static void renderGameObjects(const std::vector<GameObject*>& gameObjectsList)
{
	for (int i = 0; i < gameObjectsList.size(); i++) 
	{
		        
		gameObjectsList[i]->renderObj();
		      
		    }
}
/// </game logic:vector with cards>

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

	//after successfully created window and render:

	//cardBack (1 background (or 1 card to be multiply)
	cardBack = new GameObject("assets/cards/jungle-01.jpg", "jungleB", 0, 0); //jungle.jpg
	//horizontal (4 cards)
	card1 = new GameObject("assets/cards/foxGreen.png", "foxG", 0, 0);
	gameObjectsList.push_back(card1);// ok with static
	
	card2 = new GameObject("assets/cards/lionBlue.png", "lionB", 200, 0);
	gameObjectsList.push_back(card2); // ok with static


	card3 = new GameObject("assets/cards/raccoonPink.png", "raccoonP", 400, 0);
	gameObjectsList.push_back(card3); // ok with static

	card4 = new GameObject("assets/cards/beaverRed.png", "beaverR", 600, 0);
	gameObjectsList.push_back(card4); // ok with static

	////vertical - col1 (3 cards)
	card5 = new GameObject("assets/cards/skunkOrange.png", "skunk", 0, 200);
	gameObjectsList.push_back(card5);// ok with static

	card6 = new GameObject("assets/cards/hippoGold.png", "hippoG", 200, 200);
	gameObjectsList.push_back(card6);// ok with static

	card7 = new GameObject("assets/cards/sealOrange.png", "sealO", 400, 200);
	gameObjectsList.push_back(card7); // ok with static

	card8 = new GameObject("assets/cards/catPink.png", "catP", 600, 200);
	gameObjectsList.push_back(card8); // ok with static

	////
	// ? 2 vectors X 8 cards or 1 vector X 16 cards
	////vertical - col2 (3 cards)
	//card1 = new GameObject("assets/cards/foxGreen.png", 200, 200);
	//card2 = new GameObject("assets/cards/lionBlue.png", 200, 400);
	//card3 = new GameObject("assets/cards/raccoonPink.png", 200, 600);

	////vertical - col3 (3 cards)
	//card4 = new GameObject("assets/cards/beaverRed.png", 600, 0);
	//card5 = new GameObject("assets/cards/skunkOrange.png", 0, 200);
	//card6 = new GameObject("assets/cards/hippoGold.png", 0, 400);
	////vertical - col4 (3 cards)
	//card7 = new GameObject("assets/cards/sealOrange.png", 0, 600);
	//card8 = new GameObject("assets/cards/catPink.png", 200, 0);

	std::cout << "Object/s created.\n";
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
	case SDL_MOUSEBUTTONDOWN: //by clicking with the mouse

		int mx, my;
		int w, h;
		SDL_GetWindowSize(window, &w, &h);
		std::cout << "Screen size: " << w << " / " << h << " ";

		SDL_GetMouseState(&mx, &my); //mouse coordinates
		std::cout << "Coordinates: " << mx << " / " << my << std::endl;

		//to define the coordinates on which, when clicked, the particular image is displayed:
		if (mx < w / 4 && my < h / 4)
		{
			//ok (fox)
			card1->updateObj();

			/*if (GameObject::isFace = true)
			{
				card1->updateObj();
				GameObject::isFace = false;
			}*/
		}
		else if ((mx >= w / 4 && mx < w / 2) && my < h / 4)//(mx < w / 4 && (my >= h / 4 && my < h/2))
		{
			//ok (lion)
			card2->updateObj();

		}
		else if ((mx >= w / 2 && mx < 600) && my < h / 4)
		{
			//ok (raccoon)
			card3->updateObj();
		}
		else if ((mx > 600 && mx <= w) && my < h / 4)
		{
			//ok (beaver)
			card4->updateObj();
		}

		else if (mx < w / 4 && (my >= h / 4 && my < h / 2))
		{
			//ok (skunk)
			//card5->updateObj();
		}
		else if ((mx > w / 4 && mx < w / 2) && (my >= h / 4 && my < h / 2))
		{
			//ok (hippo)
			//card6->updateObj();
		}
		else if ((mx > w / 2 && mx < 600 ) && (my >= h / 4 && my < h/2))
		{

		//ok(seal) 
			//card7->updateObj();
		}
		else if ((mx > 600 && mx < w ) && (my >= h / 4 && my < h/2))
		{

			//(cat) 
				//card8->updateObj();
		}

	default:
		break;
	}
}

void Game::update()
{
	//with GameObject class:
	cardBack->updateBack();
	
	// card1, card2, card3, card4 are in case SDL_MOUSEBUTTONDOWN: [if-else];
	// card1->updateObj();
	// card2->updateObj();
	// card3->updateObj();
	// card4->updateObj();
	 card5->updateObj();
	 card6->updateObj();
	 card7->updateObj();
	 card8->updateObj();
	//std::cout << "Update object.\n";
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//This is where we add all of our textures to be rendered

	cardBack->renderBack();

	/*card1->renderObj(); 
	card2->renderObj();[...]*/ //render each card individually 

	//displays only  updated cards:
	renderGameObjects(gameObjectsList); // ok with static: no need to render each card individually 
	//std::cout << "card/background\n";

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