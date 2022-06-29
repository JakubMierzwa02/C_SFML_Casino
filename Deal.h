#pragma once

#include "Hand.h"
#include "Button.h"

class Deal
{
private:
	// Resources
	sf::RenderWindow* window;
	sf::Font font;

	// Mouse positions
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// Hand
	Hand* hand;

	// Cards
	std::vector<Card*> cards;
	std::vector<Card*> handCards;

	// Buttons
	std::map<std::string, Button*> buttons;
	std::vector<bool> isChecked;

	// Payment
	int coin;
	int wager;
	int multiplier;
	int payout;

	// Logic
	int counter;

	// Initializer functions
	void initVariables();
	void initHand();
	void initButtons();

public:
	// Constructor / Destructor
	Deal(sf::RenderWindow*, std::vector<Card*>, int, int, sf::Font);
	virtual ~Deal();

	const int checkHand();

	bool canPress();

	// Functions
	void updateMousePos();
	void updateButtons();
	void update();
	void renderButtons(sf::RenderTarget*);
	void render(sf::RenderTarget*);
};