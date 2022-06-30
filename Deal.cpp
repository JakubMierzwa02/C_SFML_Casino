#include "Deal.h"

void Deal::initVariables()
{
	this->counter = 10;

	for (size_t i = 0; i < 5; i++)
	{
		this->isChecked.push_back(false);
	}
}

void Deal::initHandCards()
{
	// Check if the card is duplicated
	for (int i = 0; i < 5; i++)
	{
		this->handCards.push_back(this->cards[std::rand() % 51 + 1]);
		for (int j = i - 1; j >= 0 && i > 0; j--)
		{
			if ((this->handCards[j]->getValue() == this->handCards[i]->getValue())
				&& (this->handCards[j]->getColor() == this->handCards[i]->getColor()))
			{
				this->handCards.erase(this->handCards.begin() + i);
				i--;
				break;
			}
		}
	}

	// Init used cards
	for (size_t i = 0; i < 5; i++)
	{
		this->usedCards.push_back(*this->handCards[i]);
	}
}

void Deal::initHand()
{
	// Init hand
	this->hand = new Hand(this->handCards, 210.f, 530.f, 100.f);
}

void Deal::initButtons()
{
	this->buttons["HOLD_1"] = new Button(265.f, 450.f, 100.f, 60.f,
		this->font, "Hold",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));

	this->buttons["HOLD_2"] = new Button(585.f, 450.f, 100.f, 60.f,
		this->font, "Hold",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));

	this->buttons["HOLD_3"] = new Button(905.f, 450.f, 100.f, 60.f,
		this->font, "Hold",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));

	this->buttons["HOLD_4"] = new Button(1225.f, 450.f, 100.f, 60.f,
		this->font, "Hold",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));

	this->buttons["HOLD_5"] = new Button(1545.f, 450.f, 100.f, 60.f,
		this->font, "Hold",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));
}

Deal::Deal(sf::RenderWindow* window, std::vector<Card*> cards, int coin, int wager, sf::Font font)
	: cards(cards), coin(coin), wager(wager), font(font)
{
	this->window = window;
	this->initVariables();
	this->initHandCards();
	this->initHand();
	this->initButtons();
}

Deal::~Deal()
{
	delete this->hand;
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

bool Deal::canPress()
{
	if (this->counter < 20)
	{
		this->counter++;
		return false;
	}
	return true;
}

void Deal::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Deal::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->canPress())
	{
		if (this->buttons["HOLD_1"]->isPressed())
		{
			if (!this->isChecked[0])
			{
				this->isChecked[0] = true;
			}
			else
			{
				this->isChecked[0] = false;
			}
			this->counter = 0;
		}
		else if (this->buttons["HOLD_2"]->isPressed())
		{
			if (!this->isChecked[1])
			{
				this->isChecked[1] = true;
			}
			else
			{
				this->isChecked[1] = false;
			}
			this->counter = 0;
		}
		else if (this->buttons["HOLD_3"]->isPressed())
		{
			if (!this->isChecked[2])
			{
				this->isChecked[2] = true;
			}
			else
			{
				this->isChecked[2] = false;
			}
			this->counter = 0;
		}
		else if (this->buttons["HOLD_4"]->isPressed())
		{
			if (!this->isChecked[3])
			{
				this->isChecked[3] = true;
			}
			else
			{
				this->isChecked[3] = false;
			}
			this->counter = 0;
		}
		else if (this->buttons["HOLD_5"]->isPressed())
		{
			if (!this->isChecked[4])
			{
				this->isChecked[4] = true;
			}
			else
			{
				this->isChecked[4] = false;
			}
			this->counter = 0;
		}
	}

	if (this->isChecked[0])
		this->buttons["HOLD_1"]->checked();
	if (this->isChecked[1])
		this->buttons["HOLD_2"]->checked();
	if (this->isChecked[2])
		this->buttons["HOLD_3"]->checked();
	if (this->isChecked[3])
		this->buttons["HOLD_4"]->checked();
	if (this->isChecked[4])
		this->buttons["HOLD_5"]->checked();
}

void Deal::updateHand()
{
	delete this->hand;
	for (size_t i = 0; i < 5; i++)
	{
		if (!this->isChecked[i])
		{
			this->handCards[i] = this->cards[std::rand() % 51 + 1];
			this->usedCards.push_back(*this->handCards[i]);
			for (size_t j = 0; j < this->usedCards.size() - 1; j++)
			{
				if ((this->handCards[i]->getValue() == this->usedCards[j].getValue())
					&& (this->handCards[i]->getColor() == this->usedCards[j].getColor()))
				{
					this->handCards[i] = NULL;
					i--;
					break;
				}
			}
		}
	}

	this->initHand();
}

void Deal::update()
{
	this->updateMousePos();
	this->updateButtons();
}

void Deal::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void Deal::render(sf::RenderTarget* target)
{
	this->renderButtons(target);

	for (size_t i = 0; i < this->handCards.size(); i++)
	{
		this->hand->render(target);
	}
}