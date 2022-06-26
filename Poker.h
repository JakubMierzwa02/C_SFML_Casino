#pragma once

#include "Phase.h"
#include "Deal.h"
#include "Button.h"

class Poker : public Phase
{
private:
	// Background
	sf::Sprite background;

	// Textures
	std::vector<sf::Texture*> textures;
	sf::Texture backgroundTex;

	// Cards
	std::vector<Card*> cards;	

	// Deal
	Deal* deal;

	// Logic
	int counter;

	// Initializer functions
	void initVariables();
	void initTextures();
	void initCards();
	void initDeal();

public:
	// Constructor / Destructor
	Poker(sf::RenderWindow*);
	virtual ~Poker();

	bool canPlay();

	// Functions
	void update(const float&);
	void render(sf::RenderTarget*);
};