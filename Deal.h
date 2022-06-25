#pragma once

#include "Hand.h"

class Deal
{
private:
	// Hand
	Hand* hand;

	// Cards
	std::vector<Card*> cards;
	std::vector<Card*> handCards;

	// Initializer functions
	void initHand();

public:
	// Constructor / Destructor
	Deal(std::vector<Card*>);
	virtual ~Deal();

	void checkHand();

	// Functions
	void update(const float&);
	void render(sf::RenderTarget*);
};