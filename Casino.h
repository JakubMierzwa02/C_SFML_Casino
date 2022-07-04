#pragma once

#include "MainMenuPhase.h"

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

	// Phases
	std::stack<Phase*> phases;

	// Initialier functions
	void initWindow();
	void initPhase();

public:
	// Constructor / Destructor
	Casino();
	virtual ~Casino();

	void endApp();

	// Functions
	void updateEvents();
	void updateDt();
	void update();
	void render();
	void run();
};