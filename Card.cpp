#include "Card.h"
#include "Game.h"

Card::Card(const char* faceTextureSheet, const char* backTextureSheet, std::string id, int x, int y, bool isFace)
{
	FaceTexture = TextureManager::loadTexture(faceTextureSheet); //to load the face texture
	BackTexture = TextureManager::loadTexture(backTextureSheet); //to load the back texture

	this->id = id;
	this->xpos = x;
	this->ypos = y;

	this->isFace = isFace; 
	this->id = id;

	//new:
	cardMap[id] = FaceTexture; //to randomize in Board.cpp

}

//to load BackTexture
void Card::updateBack()
{
	srcRect.h = 200; 
	srcRect.w = 200; 
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;


	SDL_RenderCopy(Game::renderer, BackTexture, &srcRect, &destRect);
}


//to load FaceTexture
void Card::updateFace()
{
	srcRect.h = 200; 
	srcRect.w = 200; 
	srcRect.x = 0; 
	srcRect.y = 0; 

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	SDL_RenderCopy(Game::renderer, FaceTexture, &srcRect, &destRect);
}

void Card::renderCard()
{
	if (isFace)
	{
		updateFace();
		//std::cout << "Render Face" << std::endl;	
	}
	else
	{
		updateBack();
		//std::cout << "Render Back" << std::endl;
	}
}


void Card::setIsFace(bool isFace)
{
	this->isFace = isFace;
}

//TODO: 
void Card::switchFaceBack()
{
	//todo ne razboti 6
	/*SDL_Event event2;

	SDL_PollEvent(&event2);

	event2.type = SDL_MOUSEBUTTONDOWN;

	std::cout << "event2.type = SDL_MOUSEBUTTONDOWN;" << std::endl;

	if (this->isFace = false)
		setIsFace(true);

	if (this->isFace = true)
		setIsFace(false);*/
}

bool Card::getIsFace()
{
	return this->isFace;
}

std::string Card::getID()
{
	//std::cout << "ID\n";
	return this->id;
}


//void Card::mouseClicking()
//{
//
//	//from Game.cpp // from Board:
//
//	SDL_Event event1;
//
//	SDL_PollEvent(&event1);
//
//	event1.type = SDL_MOUSEBUTTONDOWN; //by clicking with the mouse
//
//	int mx, my;
//	int w = 800, h = 800;
//
//	std::cout << "Screen size: " << w << " / " << h << " ";
//
//	SDL_GetMouseState(&mx, &my); //mouse coordinates
//	std::cout << "Coordinates: " << mx << " / " << my << std::endl;
//
//	//to define the coordinates on which, when clicked, the particular image is displayed:
//	if (mx < w / 4 && my < h / 4)
//	{
//
//		if (isFace)
//		{
//			updateFace();
//			//std::cout << "Render Face" << std::endl;	
//		}
//		else
//		{
//			updateBack();
//			//std::cout << "Render Back" << std::endl;
//		}
//
//	}
//	else if ((mx >= w / 4 && mx < w / 2) && my < h / 4)//(mx < w / 4 && (my >= h / 4 && my < h/2))
//	{
//
//		if (isFace)
//		{
//			updateFace();
//			//std::cout << "Render Face" << std::endl;	
//		}
//		else
//		{
//			updateBack();
//			//std::cout << "Render Back" << std::endl;
//		}
//
//
//	}
//	else if ((mx >= w / 2 && mx < 600) && my < h / 4)
//	{
//		// (raccoon)
//
//	}
//	else if ((mx > 600 && mx <= w) && my < h / 4)
//	{
//		// (beaver)
//
//	}
//
//	else if (mx < w / 4 && (my >= h / 4 && my < h / 2))
//	{
//		// (skunk)
//
//	}
//	else if ((mx > w / 4 && mx < w / 2) && (my >= h / 4 && my < h / 2))
//	{
//		// (hippo)
//
//	}
//	else if ((mx > w / 2 && mx < 600) && (my >= h / 4 && my < h / 2))
//	{
//
//		//(seal) 
//
//	}
//	else if ((mx > 600 && mx < w) && (my >= h / 4 && my < h / 2))
//	{
//		//(cat) 		
//	}
//}

Card::~Card()
{
}

