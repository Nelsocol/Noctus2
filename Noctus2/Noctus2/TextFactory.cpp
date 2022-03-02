#include "TextFactory.h"

void TextFactory::DrawText(sf::RenderWindow *window, std::string value, sf::Font font, sf::Color color)
{
    this->WrapString(&value, window, font);

    sf::Text text; 
    text.setFont(font);
    text.setString(value);
    text.setCharacterSize(TEXT_DEFAULT_SIZE);
    text.setFillColor(color);
    window->draw(text);
}

void TextFactory::WrapString(std::string *value, sf::RenderWindow* window, sf::Font font)
{
    int windowWidth = window->getSize().x;
    int glyphWidth = font.getGlyph('a', TEXT_DEFAULT_SIZE, false).bounds.width + 2;

    int currentLineWidth = 0;
    int lastSpaceIndex = -1;

    for (int i = 0; i < value->length(); i++) {
        if ((*value)[i] == '\n') { 
            currentLineWidth = 0;
        }
        else if ((*value)[i] == ' ')
        {
            lastSpaceIndex = i;
        }
        else if(currentLineWidth >= windowWidth)
        {
            if (lastSpaceIndex == -1)
            {
                value->insert(i, "\n");
                currentLineWidth = 0;
            }
            else
            {
                (*value)[lastSpaceIndex] = '\n';
                currentLineWidth = (i - lastSpaceIndex) * glyphWidth;
                lastSpaceIndex = -1;
            }
        }
        currentLineWidth += glyphWidth;
    }
}
