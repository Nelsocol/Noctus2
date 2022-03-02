#pragma once

#include <SFML\Graphics.hpp>

#define TEXT_DEFAULT_COLOR 0xe8e8edff

class TextFragment
{
public:
	TextFragment(std::string value, sf::Color color = sf::Color(TEXT_DEFAULT_COLOR));

	std::string value;
	sf::Color color = sf::Color(TEXT_DEFAULT_COLOR);
};
