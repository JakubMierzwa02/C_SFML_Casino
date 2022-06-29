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
	std::vector<Card> usedCards;
<<<<<<< Updated upstream
=======

	// Buttons
	std::map<std::string, Button*> buttons;
	std::vector<bool> isChecked;
>>>>>>> Stashed changes

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
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
	void initVariables();
	void initHandCards();
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
	void initVariables();
>>>>>>> Card_exchange_system
	void initHand();
	void initButtons();

public:
	// Constructor / Destructor
	Deal(sf::RenderWindow*, std::vector<Card*>, int, int, sf::Font);
	virtual ~Deal();

	const int checkHand();

	bool canPress();

	// Functions
<<<<<<< HEAD
<<<<<<< Updated upstream
	void update(const float&);
=======
	void updateMousePos();
	void updateButtons();
	void updateHand();
	void update();
	void renderButtons(sf::RenderTarget*);
>>>>>>> Stashed changes
=======
	void updateMousePos();
	void updateButtons();
	void update();
	void renderButtons(sf::RenderTarget*);
>>>>>>> Card_exchange_system
	void render(sf::RenderTarget*);
};