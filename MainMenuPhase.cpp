#include "MainMenuPhase.h"

void MainMenuPhase::initFont()
{
	if (!this->font.loadFromFile("Resources/Fonts/font.ttf"))
	{
		throw "Could not load font.ttf file";
	}
}

void MainMenuPhase::initButtons()
{
	this->buttons["NEW_POKER_GAME"] = new Button(300.f, 300.f, 280.f, 90.f, 
		this->font, "New Poker Game", 
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));

	this->buttons["EXIT"] = new Button(300.f, 500.f, 280.f, 90.f,
		this->font, "Exit",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));
}


MainMenuPhase::MainMenuPhase(sf::RenderWindow* window, std::stack<Phase*>* phases)
	: Phase(window, phases)
{
	this->initFont();
	this->initButtons();
}

MainMenuPhase::~MainMenuPhase()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


void MainMenuPhase::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// New poker game
	if (this->buttons["NEW_POKER_GAME"]->isPressed())
	{
		this->phases->push(new Poker(this->window, this->phases));
	}

	// Quit game
	if (this->buttons["EXIT"]->isPressed())
	{
		this->endPhase();
	}
}

void MainMenuPhase::update(const float& dt)
{
	this->updateMousePositions();
	this->updateButtons();
}

void MainMenuPhase::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuPhase::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	this->renderButtons(target);
}
