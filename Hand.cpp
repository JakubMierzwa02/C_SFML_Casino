#include "Hand.h"

Hand::Hand(std::vector<Card*> cards, float pos_x, float pos_y, float gap)
	: cards(cards), pos_x(pos_x), pos_y(pos_y), gap(gap)
{
	
}

Hand::~Hand()
{
	for (size_t i = 0; i < cards.size(); i++)
	{
		delete this->cards[i];
	}
}

void Hand::sortHand()
{
	for (size_t i = 0; i < cards.size() - 1; i++)
		for (size_t j = 0; j < cards.size() - i - 1; j++)
			if (cards[j]->getValue() > cards[j + 1]->getValue())
				std::swap(cards[j], cards[j + 1]);
}

bool Hand::jacks_or_better()
{
	for (size_t i = 0; i < cards.size(); i++)
		for (size_t j = i + 1; j < cards.size(); j++)
			if (cards[i]->getValue() >= 11 && (cards[i]->getValue() == cards[j]->getValue()))
				return true;
	return false;
}

bool Hand::two_pairs()
{
	int pairs = 0;
	for (size_t i = 0; i < cards.size(); i++)
		for (size_t j = i + 1; j < cards.size(); j++)
			if (cards[i]->getValue() == cards[j]->getValue())
			{
				pairs++;
			}
	if (pairs == 2)
		return true;
	return false;
}

bool Hand::three_of_a_kind()
{
	for (size_t i = 0; i < cards.size(); i++)
		for (size_t j = i + 1; j < cards.size(); j++)
			for (size_t k = j + 1; k < cards.size(); k++)
				if (cards[i]->getValue() == cards[j]->getValue() && cards[i]->getValue() == cards[k]->getValue())
					return true;
	return false;
}

bool Hand::straight()
{
	this->sortHand();
	for (size_t i = 1; i < cards.size() - 1; i++)
		if (cards[i]->getValue() + 1 != cards[i - 1]->getValue())
			return false;
	return true;
}

bool Hand::flush()
{
	for (size_t i = 1; i < cards.size() - 1; i++)
		if (cards[i]->getColor() != cards[i - 1]->getColor())
			return false;
	return true;
}

bool Hand::full_house()
{
	return false;
}

bool Hand::four_of_a_kind()
{
	return false;
}

bool Hand::straight_flush()
{
	return false;
}

void Hand::update()
{

}

void Hand::render(sf::RenderTarget* target)
{
	float pos = 0;
	float width = this->cards[0]->getBounds().width + this->gap;
	for (size_t i = 0; i < this->cards.size(); i++)
	{
		this->cards[i]->setPosition(this->pos_x + pos, this->pos_y);
		this->cards[i]->render(target);
		pos += width;
	}
}
