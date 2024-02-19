#include "Game.h"

//own movement for any object
class GameObject
{
public:
	GameObject(const char* textureSheet, int x, int y); //no need for SDL_Renderer* ren
	~GameObject();

	void updateObj();
	void renderObj(); //specific behavior
	void updateBack();
	void renderBack();
private:
	
	int xpos; //���� ������ �� �������� ������ �� ������
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect; //�� ����������� 
	SDL_Renderer* renderer; //
};

