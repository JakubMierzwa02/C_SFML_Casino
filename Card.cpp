#include "Card.h"

Card::Card(sf::Texture texture, int value, Color color)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.4f, 1.4f);

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

const sf::FloatRect& Card::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Card::setPosition(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
}

void Card::update(const float& dt)
{

}

void Card::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
