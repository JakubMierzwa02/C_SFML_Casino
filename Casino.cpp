#include "Casino.h"

void Casino::initWindow()
{
	this->name = "Casino";
	this->window_width = 1280;
	this->window_height = 720;
	this->fps = 120;
	this->videoMode = sf::VideoMode(this->window_width, this->window_height);

	this->window = new sf::RenderWindow(this->videoMode, this->name, sf::Style::Default);
	this->window->setFramerateLimit(fps);
}

Casino::Casino()
{
	this->initWindow();
}

Casino::~Casino()
{
	delete this->window;
}

void Casino::updateEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window->close();
	}
}

void Casino::updateDt()
{
	// Updates the dt variable with the time it takes to update and render one frame
	this->dt = this->clock.restart().asSeconds();
}

void Casino::update()
{
	this->updateEvents();
}

void Casino::render()
{
	this->window->clear();

	// Render stuff

	this->window->display();
}

void Casino::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
