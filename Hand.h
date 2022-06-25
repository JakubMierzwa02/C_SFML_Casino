#pragma once

#include "Card.h"

class Hand
{
private:
	std::vector<Card*> cards;
	float pos_x;
	float pos_y;
	float gap;

public:
	// Constructor / Destructor
	Hand(std::vector<Card*>, float, float, float);
	virtual ~Hand();

	// Functions
	void update();
	void render(sf::RenderTarget*);
};