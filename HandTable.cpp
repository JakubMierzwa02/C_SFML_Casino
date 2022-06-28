#include "HandTable.h"

void HandTable::initText()
{
	this->info.setFont(this->font);
	this->info.setPosition(50.f, 7.f);
	this->info.setCharacterSize(32);
	this->info.setFillColor(sf::Color::Yellow);
	this->info.setOutlineColor(sf::Color::Black);
	this->info.setOutlineThickness(2);
	this->info.setString("Coins wagered");

	this->handText.setFont(this->font);

	this->handText.setString("Straight flush \n"
						 "Four of a kind \n"
						 "Full house \n"
						 "Flush \n"
						 "Straight \n"
						 "Three of a kind \n"
						 "Two pairs \n"
						 "Jacks or better");
	this->handText.setCharacterSize(32);
	this->handText.setPosition(this->shape.getPosition().x + 20.f, this->shape.getPosition().y + 20.f);

	this->coinText.setFont(this->font);

	this->coinText.setString("250 \n"
		"125 \n"
		"45 \n"
		"30 \n"
		"20 \n"
		"15 \n"
		"10 \n"
		"5");
	this->coinText.setCharacterSize(32);
	this->coinText.setPosition(this->shape.getPosition().x + 350.f, this->shape.getPosition().y + 20.f);
}

HandTable::HandTable(float pos_x, float pos_y, float width, float height, sf::Font font)
{
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setSize(sf::Vector2f(width, height));

	this->shape.setFillColor(sf::Color(0, 0, 0, 190));
	this->shape.setOutlineColor(sf::Color::Yellow);
	this->shape.setOutlineThickness(3);

	this->font = font;

	this->initText();
}

HandTable::~HandTable()
{

}

void HandTable::render(sf::RenderTarget* target)
{
	target->draw(this->info);
	target->draw(this->shape);
	target->draw(this->handText);
	target->draw(this->coinText);
}
