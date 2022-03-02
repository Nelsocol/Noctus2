#include "TextFactory.h"

/*
    Draws a textfragment to the screen with the given offset string.
*/
std::string TextFactory::DrawText(TextFragment fragment, std::string offsetString)
{
    fragment.value.insert(0, offsetString);
    std::string returnString = this->WrapString(&(fragment.value), window, font);

    sf::Text text; 
    text.setFont(*font);
    text.setString(fragment.value);
    text.setCharacterSize(TEXT_DEFAULT_SIZE);
    text.setFillColor(fragment.color);
    window->draw(text);

    return returnString;
}

/*
    Inserts newlines into the given string so that words neatly wrap at the edge of the frame.
*/
std::string TextFactory::WrapString(std::string *value, sf::RenderWindow* window, sf::Font* font)
{
    std::string newOffsetString = "";

    int windowWidth = window->getSize().x;
    int glyphWidth = font->getGlyph('a', TEXT_DEFAULT_SIZE, false).bounds.width + 2;

    int currentLineWidth = 0;
    int lastSpaceIndex = -1;

    for (int i = 0; i < value->length(); i++) {
        //If the character is a already newline then record that newline in the offset and reset line length.
        if ((*value)[i] == '\n') { 
            currentLineWidth = 0;
            newOffsetString.append("\n");
        }
        else if ((*value)[i] == ' ') // If the character is a space record that index as the last space index.
        {
            lastSpaceIndex = i;
        }
        else if(currentLineWidth >= windowWidth) // It the current word overfill the line.
        {
            if (lastSpaceIndex == -1) // If the word is more than a whole line long then insert a newline partway through the string.
            {
                value->insert(i, "\n");
                currentLineWidth = 0;
            }
            else // Otherwise insert a newline before the current word, shifting the word to the next line.
            {
                (*value)[lastSpaceIndex] = '\n';
                currentLineWidth = (i - lastSpaceIndex) * glyphWidth;
                lastSpaceIndex = -1;
            }
            newOffsetString.append("\n");
        }
        currentLineWidth += glyphWidth;
    }

    // Add a space to the offset character for each character in the value from the end to the last newline.
    int lastNewline = value->length(); 
    while ((*value)[--lastNewline] != '\n') {
        newOffsetString.append(" ");
    }

    // Return offset string for chaining.
    return newOffsetString;
}
