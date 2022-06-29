#include "Button.h"

Button::Button(float pos_x, float pos_y, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDLE;

	this->shape.setPosition(pos_x, pos_y);
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;

	this->text.setFont(this->font);
	this->text.setCharacterSize(32);
	this->text.setFillColor(sf::Color::Yellow);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(2);
	this->text.setString(text);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f - 4.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f - 5.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	return this->buttonState == BTN_ACTIVE;
}

void Button::checked()
{
	this->buttonState = BTN_CHECKED;
}

void Button::update(sf::Vector2f mousePos)
{
	// Idle
	if (this->buttonState != BTN_CHECKED)
		this->buttonState = BTN_IDLE;

	// Hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		// Active
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	// Change color
	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;
	case BTN_CHECKED:
		this->shape.setFillColor(sf::Color::Green);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}