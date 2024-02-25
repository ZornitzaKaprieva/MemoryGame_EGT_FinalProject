#pragma once
#include "TextureManager.h"

class Card
{
public:
	Card() {} //default constructor 
	Card(const char* faceTexture, const char* backTexture, std::string name, int x, int y, bool isFace); //constructor for a single card with 6 parameters

	void renderCard(); // for displaying cards(face and back)

	//TODO:
	void switchFaceBack(); //function that handles the isFalse variable:
	void setIsFace(bool face); //setter for bool isFace
	bool getIsFace(); //getter for bool isFace

	void setName(std::string name);
	std::string getName(); //for randomize cards in array 
	void setPos(int x, int y); // for randomize cards in array 

	int getXpos() { return this->xpos; }
	int getYpos() { return this->ypos; }

	//void mouseClicking();//modified from Board.cpp

	~Card(); //destructor

private:
	//separate methods for the back and face of the card:
	void updateBack(); //void drawBack();
	void updateFace(); //void drawFace();

	std::string name;

	int xpos;
	int ypos;
	bool isFace;
	SDL_Texture* FaceTexture; //texture for card`s back
	SDL_Texture* BackTexture; //texture for card`s face
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};