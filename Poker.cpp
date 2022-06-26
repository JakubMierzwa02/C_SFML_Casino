#include "Poker.h"

void Poker::initVariables()
{
	this->counter = 20;
	this->money = 100000;
}

void Poker::initTextures()
{
	for (int i = 0; i < 52; i++)
		this->textures.push_back(new sf::Texture());

	// Load textures
	this->textures[0]->loadFromFile("Resources/Cards/2_of_clubs.png");
	this->textures[1]->loadFromFile("Resources/Cards/3_of_clubs.png");
	this->textures[2]->loadFromFile("Resources/Cards/4_of_clubs.png");
	this->textures[3]->loadFromFile("Resources/Cards/5_of_clubs.png");
	this->textures[4]->loadFromFile("Resources/Cards/6_of_clubs.png");
	this->textures[5]->loadFromFile("Resources/Cards/7_of_clubs.png");
	this->textures[6]->loadFromFile("Resources/Cards/8_of_clubs.png");
	this->textures[7]->loadFromFile("Resources/Cards/9_of_clubs.png");
	this->textures[8]->loadFromFile("Resources/Cards/10_of_clubs.png");
	this->textures[9]->loadFromFile("Resources/Cards/jack_of_clubs.png");
	this->textures[10]->loadFromFile("Resources/Cards/queen_of_clubs.png");
	this->textures[11]->loadFromFile("Resources/Cards/king_of_clubs.png");
	this->textures[12]->loadFromFile("Resources/Cards/ace_of_clubs.png");

	this->textures[13]->loadFromFile("Resources/Cards/2_of_spades.png");
	this->textures[14]->loadFromFile("Resources/Cards/3_of_spades.png");
	this->textures[15]->loadFromFile("Resources/Cards/4_of_spades.png");
	this->textures[16]->loadFromFile("Resources/Cards/5_of_spades.png");
	this->textures[17]->loadFromFile("Resources/Cards/6_of_spades.png");
	this->textures[18]->loadFromFile("Resources/Cards/7_of_spades.png");
	this->textures[19]->loadFromFile("Resources/Cards/8_of_spades.png");
	this->textures[20]->loadFromFile("Resources/Cards/9_of_spades.png");
	this->textures[21]->loadFromFile("Resources/Cards/10_of_spades.png");
	this->textures[22]->loadFromFile("Resources/Cards/jack_of_spades.png");
	this->textures[23]->loadFromFile("Resources/Cards/queen_of_spades.png");
	this->textures[24]->loadFromFile("Resources/Cards/king_of_spades.png");
	this->textures[25]->loadFromFile("Resources/Cards/ace_of_spades.png"); 

	this->textures[26]->loadFromFile("Resources/Cards/2_of_diamonds.png");
	this->textures[27]->loadFromFile("Resources/Cards/3_of_diamonds.png");
	this->textures[28]->loadFromFile("Resources/Cards/4_of_diamonds.png");
	this->textures[29]->loadFromFile("Resources/Cards/5_of_diamonds.png");
	this->textures[30]->loadFromFile("Resources/Cards/6_of_diamonds.png");
	this->textures[31]->loadFromFile("Resources/Cards/7_of_diamonds.png");
	this->textures[32]->loadFromFile("Resources/Cards/8_of_diamonds.png");
	this->textures[33]->loadFromFile("Resources/Cards/9_of_diamonds.png");
	this->textures[34]->loadFromFile("Resources/Cards/10_of_diamonds.png");
	this->textures[35]->loadFromFile("Resources/Cards/jack_of_diamonds.png");
	this->textures[36]->loadFromFile("Resources/Cards/queen_of_diamonds.png");
	this->textures[37]->loadFromFile("Resources/Cards/king_of_diamonds.png");
	this->textures[38]->loadFromFile("Resources/Cards/ace_of_diamonds.png");

	this->textures[39]->loadFromFile("Resources/Cards/2_of_hearts.png");
	this->textures[40]->loadFromFile("Resources/Cards/3_of_hearts.png");
	this->textures[41]->loadFromFile("Resources/Cards/4_of_hearts.png");
	this->textures[42]->loadFromFile("Resources/Cards/5_of_hearts.png");
	this->textures[43]->loadFromFile("Resources/Cards/6_of_hearts.png");
	this->textures[44]->loadFromFile("Resources/Cards/7_of_hearts.png");
	this->textures[45]->loadFromFile("Resources/Cards/8_of_hearts.png");
	this->textures[46]->loadFromFile("Resources/Cards/9_of_hearts.png");
	this->textures[47]->loadFromFile("Resources/Cards/10_of_hearts.png");
	this->textures[48]->loadFromFile("Resources/Cards/jack_of_hearts.png");
	this->textures[49]->loadFromFile("Resources/Cards/queen_of_hearts.png");
	this->textures[50]->loadFromFile("Resources/Cards/king_of_hearts.png");
	this->textures[51]->loadFromFile("Resources/Cards/ace_of_hearts.png");

	// Init background
	if (!this->backgroundTex.loadFromFile("Resources/background.jpg"))
		throw "Could not load background.jpg file";
	this->background.setTexture(this->backgroundTex);
	this->background.setScale(2.5f, 2.f);
}

void Poker::initFont()
{
	if (!this->font.loadFromFile("Resources/Fonts/font.ttf"))
		throw "Could not load font.ttf file";
}

void Poker::initCards()
{
	int i = 0;

	// Create cards
	for (int j = 2; j <= 14; j++)
	{
		this->cards.push_back(new Card(*this->textures[i], j, CLUBS));
		i++;
	}
	for (int j = 2; j <= 14; j++)
	{
		this->cards.push_back(new Card(*this->textures[i], j, SPADES));
		i++;
	}
	for (int j = 2; j <= 14; j++)
	{
		this->cards.push_back(new Card(*this->textures[i], j, DIAMONDS));
		i++;
	}
	for (int j = 2; j <= 14; j++)
	{
		this->cards.push_back(new Card(*this->textures[i], j, HEARTS));
		i++;
	}
}

void Poker::initButtons()
{
	this->buttons["DEAL"] = new Button(100, 500, 120, 74, 
		this->font, "Deal", 
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));
}

void Poker::initGui()
{
	// Hand text
	this->handText.setFont(this->font);
	this->handText.setFillColor(sf::Color::White);
	this->handText.setCharacterSize(42);
	this->handText.setPosition(this->window->getSize().x / 2.f - this->handText.getGlobalBounds().width - 100.f, 400.f);

	// Money text
	this->moneyText.setFont(this->font);
	this->moneyText.setFillColor(sf::Color::White);
	this->moneyText.setCharacterSize(42);
	this->moneyText.setPosition(200.f, 400.f);
	this->moneyText.setString('$' + std::to_string(this->money));
}

void Poker::initDeal()
{
	this->deal = new Deal(this->cards, 100, 500);
	this->updateMoney();
}

Poker::Poker(sf::RenderWindow* window)
	: Phase(window)
{
	this->initVariables();
	this->initTextures();
	this->initFont();
	this->initCards();
	this->initButtons();
	this->initGui();
	this->initDeal();
}

Poker::~Poker()
{
	for (size_t i = 0; i < this->textures.size(); i++)
	{
		delete this->textures[i];
	}

	for (size_t i = 0; i < this->cards.size(); i++)
	{
		delete this->cards[i];
	}

	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

bool Poker::canPlay()
{
	if (this->counter < 50)
	{
		this->counter++;
		return false;
	}
	return true;
}

void Poker::updateMoney()
{
	this->money += this->deal->checkHand().second;
}

void Poker::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// Deal
	if (this->canPlay())
	{
		if (this->buttons["DEAL"]->isPressed())
		{
			delete this->deal;
			this->initDeal();
			this->counter = 0;
		}
	}
}

void Poker::updateGui()
{
	this->handText.setString(this->deal->checkHand().first);
	this->moneyText.setString('$' + std::to_string(this->money));
}

void Poker::update(const float& dt)
{
	this->updateMousePositions();
	this->updateButtons();
	this->updateGui();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endPhase();
}

void Poker::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void Poker::renderGui(sf::RenderTarget* target)
{
	target->draw(this->handText);
	target->draw(this->moneyText);
}

void Poker::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	target->draw(this->background);

	this->renderButtons(target);
	this->renderGui(target);

	if (this->deal)
		this->deal->render(target);
}
