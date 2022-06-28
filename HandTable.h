#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class HandTable
{
private:
	sf::RectangleShape shape;

	sf::Font font;
	sf::Text handText;
	sf::Text coinText;

	// Initializer functions
	void initText();

public:
	// Constructor / Destructor
	HandTable(float, float, float, float, sf::Font);
	virtual ~HandTable();

	void render(sf::RenderTarget*);
};