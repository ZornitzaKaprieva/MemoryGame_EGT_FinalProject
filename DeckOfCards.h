
#include <string>
#include"GameObject.h";

class DeckOfCards
{
public:
	DeckOfCards(); // constructor initializes deck
	void shuffle(); // shuffles cards in deck
	void deal(); // deals shuffled cards
 
private:
	GameObject* gameObject;
	static std::vector<GameObject*> gameObjects;


};