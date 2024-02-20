#pragma once

#include<string>

#include "Game.h"
//#include"GameLogic.h" //тук или обратно ( #include"GameObject.h" in class GameLogic

class GameObject
{
public:
	GameObject(const char* textureSheet, std::string id, int x, int y); //no need for SDL_Renderer* ren
	~GameObject();

	void updateObj();
	void renderObj(); //specific behavior
	void updateBack();
	void renderBack();

	//? from game logic:
	//static void addGameObjectGO(GameObject* gameObject); //
	//static void renderGameObjectsGO(const std::vector<GameObject*>& gameObjects);
	

	//? for bool isFace
	void isFaceUp(bool isFace);
	
	//static bool isFace; //before - private non-static

private:
	int xpos; 
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect; 
	SDL_Renderer* renderer;

	//newTry bool:
	bool isFace;

	//from Game logic: creating vector with objects //to do 
	 //GameObject* gameObject;
	// static std::vector<GameObject*> gameObjects;
};
