#include "Casino.h"

void Casino::initWindow()
{
	srand(time(NULL));

	this->name = "Casino";
	this->window_width = 1280;
	this->window_height = 720;
	this->fps = 120;
	this->videoMode = sf::VideoMode(this->window_width, this->window_height);

	this->window = new sf::RenderWindow(this->videoMode, this->name, sf::Style::Default);
	this->window->setFramerateLimit(fps);
}

void Casino::initPhase()
{
	this->phases.push(new Poker(this->window));
}

Casino::Casino()
{
	this->initWindow();
	this->initPhase();
}

Casino::~Casino()
{
	delete this->window;
}

void Casino::endApp()
{
	std::cout << "Ending application \n";
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

	// Update phases
	if (!this->phases.empty())
	{
		this->phases.top()->update(this->dt);

		if (this->phases.top()->getQuit())
		{
			this->phases.top()->endPhase();
			delete this->phases.top();
			this->phases.pop();
		}
	}

	// App end
	else
	{
		this->endApp();
		this->window->close();
	}
}

void Casino::render()
{
	this->window->clear();

	// Render stuff
	if (!this->phases.empty())
		this->phases.top()->render();

	this->window->display();
}

void Casino::run()
{
	// Game loop
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
