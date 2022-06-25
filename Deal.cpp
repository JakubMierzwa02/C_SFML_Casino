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

void Deal::checkHand()
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
