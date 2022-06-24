#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class Casino
{
private:
	// Window
	unsigned int window_width;
	unsigned int window_height;
	sf::VideoMode videoMode;
	std::string name;
	int fps;
	sf::RenderWindow* window;

	// Clock
	sf::Clock clock;
	float dt;

	// Initialier functions
	void initWindow();

public:
	// Constructor / Destructor
	Casino();
	virtual ~Casino();

	// Functions
	void updateDt();
	void update();
	void render();
	void run();
};