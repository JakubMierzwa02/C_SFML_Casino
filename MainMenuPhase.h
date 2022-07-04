#pragma once

#include "Poker.h"
#include "Button.h"

class MainMenuPhase : public Phase
{
private:
	// Resources
	sf::Font font;

	// Buttons
	std::map<std::string, Button*> buttons;

	// Initializer functions
	void initFont();
	void initButtons();

public:
	// Constructor / Destructor
	MainMenuPhase(sf::RenderWindow*, std::stack<Phase*>*);
	virtual ~MainMenuPhase();

	// Functions
	void updateButtons();
	void update(const float&);
	void renderButtons(sf::RenderTarget* = nullptr);
	void render(sf::RenderTarget* = nullptr);
};