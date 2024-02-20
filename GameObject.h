#include "Game.h"
#include"GameLogic.h"

//own movement for any object
class GameObject
{
public:
	GameObject(const char* textureSheet, std::string id, int x, int y); //no need for SDL_Renderer* ren
	//newTry Constructor:
	GameObject(const char* textureSheet, std::string id, int x, int y, bool isFlipped);
	~GameObject();

	void updateObj();
	void renderObj(); //specific behavior
	void updateBack();
	void renderBack();
private:
	int xpos; 
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect; //�� ����������� 
	SDL_Renderer* renderer; //
	//newTry bool:
	bool isFace;

	//in Game logic: creating vector with objects //to do 
};
