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

	// Font
	sf::Font font;

	// Gui
	sf::Text handText;
	sf::Text moneyText;
	sf::Text coinText;
	sf::Text wagerText;

	// Buttons
	std::map<std::string, Button*> buttons;

	// Cards
	std::vector<Card*> cards;	

	// Deal
	Deal* deal;

	// Logic
	int counter;
	int money;

	// Initializer functions
	void initVariables();
	void initTextures();
	void initFont();
	void initCards();
	void initButtons();
	void initGui();
	void initDeal();

public:
	// Constructor / Destructor
	Poker(sf::RenderWindow*);
	virtual ~Poker();

	bool canPlay();

	// Functions
	void updateButtons();
	void updateMoney();
	void updateGui();
	void update(const float&);
	void renderButtons(sf::RenderTarget*);
	void renderGui(sf::RenderTarget*);
	void render(sf::RenderTarget*);
};