#include "TextFragment.h"

TextFragment::TextFragment(sf::RenderWindow* window, std::string value, sf::Font font, sf::Color color)
{
	this->window = window;
	this->value = value;
	this->font = font;
	this->color = color;
}
