#include "Casino.h"

void Casino::initWindow()
{
	this->name = "Casino";
	this->window_width = 1280;
	this->window_height = 720;
	this->videoMode = sf::VideoMode(this->window_width, this->window_height);

	this->window = new sf::RenderWindow(this->videoMode, this->name, sf::Style::Default);
}

Casino::Casino()
{
	this->initWindow();
}

Casino::~Casino()
{
	delete this->window;
}

void Casino::updateDt()
{
	// Updates the dt variable with the time it takes to update and render one frame
	this->dt = this->clock.restart().asSeconds();
}

void Casino::update()
{

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
