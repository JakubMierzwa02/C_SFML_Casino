#include "Phase.h"

Phase::Phase(sf::RenderWindow* window, std::stack<Phase*>* phases)
{
	this->window = window;
	this->phases = phases;
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
