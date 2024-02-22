#pragma once
#include "TextureManager.h"

class Card
{
public:
	//constructor for a single card with 6 parameters: texture for face, texture for back, id (name), xpos, ypos, bool to check is it face or back:
	Card(const char* faceTexture, const char* backTexture, std::string id, int x, int y, bool isFace);
	void renderCard();
	
	//TODO:
	//function that handles the isFalse variable:
	void switchFaceBack(); //void switchFaceBack();
	void setIsFace(bool face);
	bool getIsFace();
	std::string getID(); //new: for rondomize cards in vector 

	//void mouseClicking();//modified from Board.cpp

	~Card();

private:
	//separate methods for the back and face of the card:
	void updateBack(); //void drawBack();
	void updateFace(); //void drawFace();


public:
	//new:
	std::map<std::string, SDL_Texture*> cardMap;

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

