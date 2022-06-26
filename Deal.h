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

	// Payment
	int coin;
	int wager;
	int multiplier;
	int payout;

	// Initializer functions
	void initHand();

public:
	// Constructor / Destructor
	Deal(std::vector<Card*>, int, int);
	virtual ~Deal();

	const int checkHand();

	// Functions
	void update(const float&);
	void render(sf::RenderTarget*);
};