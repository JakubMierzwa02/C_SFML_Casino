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

	// Wager
	int coin;
	int wager;
	std::pair<std::string, int> hand_pay;

	// Initializer functions
	void initHand();

public:
	// Constructor / Destructor
	Deal(std::vector<Card*>, int, int);
	virtual ~Deal();

	const std::pair<std::string, int> checkHand();

	// Functions
	void update(const float&);
	void render(sf::RenderTarget*);
};