#include "Phase.h"

Phase::Phase(sf::RenderWindow* window)
{
	this->window = window;
	this->quit = false;
}

Phase::~Phase()
{

}

const bool Phase::getQuit() const
{
	return this->quit;
}

void Phase::endPhase()
{
	this->quit = true;
}

void Phase::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
