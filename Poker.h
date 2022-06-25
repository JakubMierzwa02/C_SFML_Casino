#pragma once

#include "Phase.h"
#include "Card.h"

class Poker : public Phase
{
private:
	// Textures
	std::vector<sf::Texture*> textures;

	// Cards
	std::vector<Card*> cards;	

	// Initializer functions
	void initTextures();
	void initCards();

public:
	// Constructor / Destructor
	Poker(sf::RenderWindow*);
	virtual ~Poker();

	// Functions
	void update(const float&);
	void render(sf::RenderTarget*);
};