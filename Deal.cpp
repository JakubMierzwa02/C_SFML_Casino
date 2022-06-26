#include "Deal.h"

void Deal::initHand()
{
	for (int i = 0; i < 5; i++)
		this->handCards.push_back(this->cards[std::rand() % 51 + 1]);

	this->hand = new Hand(this->handCards, 150.f, 100.f, 50.f);
}

Deal::Deal(std::vector<Card*> cards, int coin, int wager)
	: cards(cards), coin(coin), wager(wager)
{
	this->initHand();
}

Deal::~Deal()
{
	
}

const int Deal::checkHand()
{
	this->multiplier = -5;
	this->payout = 0;

	if (this->hand->straight_flush())
	{
		this->multiplier = 250;
	}
	else if (this->hand->four_of_a_kind())
	{
		this->multiplier = 125;
	}
	else if (this->hand->full_house())
	{
		this->multiplier = 45;
	}
	else if (this->hand->flush())
	{
		this->multiplier = 30;
	}
	else if (this->hand->straight())
	{
		this->multiplier = 20;
	}
	else if (this->hand->three_of_a_kind())
	{
		this->multiplier = 15;
	}
	else if (this->hand->two_pairs())
	{
		this->multiplier = 10;
	}
	else if (this->hand->jacks_or_better())
	{
		this->multiplier = 5;
	}
	else
	{
		this->multiplier = 0;
	}
	
	this->payout += this->coin * this->multiplier;
	this->payout -= this->wager;
	
	return this->payout;
}

void Deal::update(const float& dt)
{

}

void Deal::render(sf::RenderTarget* target)
{
	for (size_t i = 0; i < this->handCards.size(); i++)
	{
		this->hand->render(target);
	}
}
