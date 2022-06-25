#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <stack>

class Phase
{
private:

protected:
	// Window
	sf::RenderWindow* window;

	bool quit;

public:
	// Constructor / Destructor
	Phase(sf::RenderWindow*);
	virtual ~Phase();

	const bool getQuit() const;

	void endPhase();

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};