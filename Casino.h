#pragma once

#include "Phase.h"

class Casino
{
private:
	// Window
	unsigned int window_width;
	unsigned int window_height;
	sf::VideoMode videoMode;
	std::string name;
	unsigned int fps;
	sf::RenderWindow* window;

	// Event
	sf::Event ev;

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
	void updateEvents();
	void updateDt();
	void update();
	void render();
	void run();
};