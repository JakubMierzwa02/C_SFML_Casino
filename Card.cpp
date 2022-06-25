#include "Card.h"

Card::Card(sf::Texture texture, int value, Color color)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);

	this->value = value;
	this->color = color;
}

Card::~Card()
{

}

const int& Card::getValue() const
{
	return this->value;
}

const Color& Card::getColor() const
{
	return this->color;
}

void Card::update(const float& dt)
{

}

void Card::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
