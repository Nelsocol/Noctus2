#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>

#include "TextFragment.h"

#define TEXT_DEFAULT_SIZE 15

class TextFactory 
{
public:
	std::string DrawText(TextFragment fragment, std::string offsetString);
private:
	std::string WrapString(std::string *value, sf::RenderWindow *window, sf::Font font);
};
