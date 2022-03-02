#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>

#define TEXT_DEFAULT_COLOR 0xe8e8edff
#define TEXT_DEFAULT_SIZE 15

class TextFactory 
{
public:
	void DrawText(sf::RenderWindow *window, std::string value, sf::Font font, sf::Color color = sf::Color(TEXT_DEFAULT_COLOR));
private:
	void WrapString(std::string *value, sf::RenderWindow *window, sf::Font font);
};
