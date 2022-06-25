#pragma once

#include "Phase.h"
#include "Card.h"

class Poker : public Phase
{
private:
	sf::RenderWindow* window;

public:
	Poker(sf::RenderWindow*);
	virtual ~Poker();

	void update(const float&);
	void render(sf::RenderTarget*);
};