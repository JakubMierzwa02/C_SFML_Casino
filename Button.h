#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE, BTN_CHECKED };

class Button
{
private:
	unsigned short buttonState;

	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	// Constructors / Destructors
	Button(float, float, float, float, sf::Font, std::string, sf::Color, sf::Color, sf::Color);
	virtual ~Button();

	// Accessors
	const bool isPressed() const;

	// Modifiers
	void checked();

	// Functions
	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget*);
};