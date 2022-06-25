#include "Poker.h"

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

void Poker::initHand()
{
	this->game = true;
	for (int i = 0; i < 5; i++)
		this->handCards.push_back(this->cards[std::rand() % 51 + 1]);

	this->hand = new Hand(this->handCards, 100.f, 100.f, 50.f);
}

Poker::Poker(sf::RenderWindow* window)
	: Phase(window)
{
	this->initTextures();
	this->initCards();
	this->initHand();
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

	delete this->hand;
}

void Poker::checkHand()
{
	if (this->hand->straight_flush())
		std::cout << "Straight flush \n";
	else if (this->hand->four_of_a_kind())
		std::cout << "Four of a kind \n";
	else if (this->hand->full_house())
		std::cout << "Full house \n";
	else if (this->hand->flush())
		std::cout << "Flush \n";
	else if (this->hand->straight())
		std::cout << "Straight \n";
	else if (this->hand->three_of_a_kind())
		std::cout << "Three of a kind \n";
	else if (this->hand->two_pairs())
		std::cout << "Two pairs \n";
	else if (this->hand->jacks_or_better())
		std::cout << "Jacks or better \n";

	this->game = false;
}

void Poker::update(const float& dt)
{
	if (this->game)
		this->checkHand();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endPhase();
}

void Poker::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	for (size_t i = 0; i < this->handCards.size(); i++)
	{
		this->hand->render(target);
	}
}
