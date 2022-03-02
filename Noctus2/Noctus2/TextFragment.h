#pragma once

#include <SFML\Graphics.hpp>

#define TEXT_DEFAULT_COLOR 0xe8e8edff

class TextFragment
{
public:
	TextFragment(sf::RenderWindow* window, std::string value, sf::Font font, sf::Color color = sf::Color(TEXT_DEFAULT_COLOR));

	sf::RenderWindow* window;
	std::string value;
	sf::Font font;
	sf::Color color = sf::Color(TEXT_DEFAULT_COLOR);
};
