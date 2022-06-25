#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include <iostream>
#include <string>
#include <vector>

enum Color {CLUBS = 0, SPADES = 1, DIAMONDS = 2, HEARTS = 3};

class Card
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	int value;
	Color color;

public:
	// Constructor / Destructor
	Card(sf::Texture, int, Color);
	virtual ~Card();

	// Accessors
	const int& getValue() const;
	const Color& getColor() const;

	// Functions
	void update(const float&);
	void render(sf::RenderTarget*);
};