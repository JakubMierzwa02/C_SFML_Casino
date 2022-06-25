#pragma once

#include "Phase.h"
#include "Hand.h"

class Poker : public Phase
{
private:
	// Textures
	std::vector<sf::Texture*> textures;

	// Cards
	std::vector<Card*> cards;	
	std::vector<Card*> handCards;

	// Hand
	Hand* hand;

	// Initializer functions
	void initTextures();
	void initCards();
	void initHand();

public:
	// Constructor / Destructor
	Poker(sf::RenderWindow*);
	virtual ~Poker();

	// Functions
	void checkHand();

	void update(const float&);
	void render(sf::RenderTarget*);
};