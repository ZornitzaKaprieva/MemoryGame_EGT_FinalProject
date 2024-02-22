#pragma once
#include "TextureManager.h"

class Card
{
public:
	//constructor for a single card with 6 parameters: texture for face, texture for back, id (name), xpos, ypos, bool to check is it face or back:
	Card(const char* faceTexture, const char* backTexture, std::string id, int x, int y, bool isFace);
	void render();
	
private:
	//separate methods for the back and face of the card:
	void updateBack(); //void drawBack();
	void updateFace(); //void drawFace();

	//TODO:
	//function that handles the isFalse variable:
	void switchFaceBack(); //void switchFaceBack();
	void setIsFace(bool face);
	bool getIsFace();

	~Card();
private:
	std::string id;
	int xpos;
	int ypos;
	bool isFace;
	SDL_Texture* FaceTexture; //texture for card`s back
	SDL_Texture* BackTexture; //texture for card`s face
	SDL_Rect srcRect, destRect; 
	SDL_Renderer* renderer;
};

