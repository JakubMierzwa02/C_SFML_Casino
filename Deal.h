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
	std::vector<Card> usedCards;
<<<<<<< Updated upstream
=======

	// Buttons
	std::map<std::string, Button*> buttons;
	std::vector<bool> isChecked;
>>>>>>> Stashed changes

	// Payment
	int coin;
	int wager;
	int multiplier;
	int payout;

	// Initializer functions
<<<<<<< Updated upstream
=======
	void initVariables();
	void initHandCards();
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
	void initHand();

public:
	// Constructor / Destructor
	Deal(std::vector<Card*>, int, int);
	virtual ~Deal();

	const int checkHand();

	// Functions
<<<<<<< Updated upstream
	void update(const float&);
=======
	void updateMousePos();
	void updateButtons();
	void updateHand();
	void update();
	void renderButtons(sf::RenderTarget*);
>>>>>>> Stashed changes
	void render(sf::RenderTarget*);
};