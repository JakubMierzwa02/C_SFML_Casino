#include "Deal.h"

void Deal::initHand()
{
	for (int i = 0; i < 5; i++)
		this->handCards.push_back(this->cards[std::rand() % 51 + 1]);

	this->hand = new Hand(this->handCards, 150.f, 100.f, 50.f);
}

Deal::Deal(std::vector<Card*> cards)
	: cards(cards)
{
	this->initHand();
}

Deal::~Deal()
{
	
}

const std::string Deal::checkHand() const
{
	std::string s = "";
	if (this->hand->straight_flush())
		s = "Straight flush";
	else if (this->hand->four_of_a_kind())
		s = "Four of a kind";
	else if (this->hand->full_house())
		s = "Full house";
	else if (this->hand->flush())
		s = "Flush";
	else if (this->hand->straight())
		s = "Straight";
	else if (this->hand->three_of_a_kind())
		s = "Three of a kind";
	else if (this->hand->two_pairs())
		s = "Two pairs";
	else if (this->hand->jacks_or_better())
		s = "Jacks or better";
	
	return s;
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
