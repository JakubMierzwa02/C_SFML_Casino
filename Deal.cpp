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

const std::pair<std::string, int> Deal::checkHand()
{
	if (this->hand->straight_flush())
	{
		this->hand_pay.second = 250;
		this->hand_pay.first = "Straight flush";
	}
	else if (this->hand->four_of_a_kind())
	{
		this->hand_pay.second = 125;
		this->hand_pay.first = "Four of a kind";
	}
	else if (this->hand->full_house())
	{
		this->hand_pay.second = 45;
		this->hand_pay.first = "Full house";
	}
	else if (this->hand->flush())
	{
		this->hand_pay.second = 30;
		this->hand_pay.first = "Flush";
	}
	else if (this->hand->straight())
	{
		this->hand_pay.second = 20;
		this->hand_pay.first = "Straight";
	}
	else if (this->hand->three_of_a_kind())
	{
		this->hand_pay.second = 15;
		this->hand_pay.first = "Three of a kind";
	}
	else if (this->hand->two_pairs())
	{
		this->hand_pay.second = 10;
		this->hand_pay.first = "Two pairs";
	}
	else if (this->hand->jacks_or_better())
	{
		this->hand_pay.second = 5;
		this->hand_pay.first = "Jacks or better";
	}
	
	this->hand_pay.second *= this->coin;
	this->hand_pay.second -= this->wager;
	
	return this->hand_pay;
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
