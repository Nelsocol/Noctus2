#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <list>

#include "TextFactory.h"
#include "NoctusParser.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 1000), "Noctus Player");
    sf::CircleShape shape(100.f);
    sf::Font font;
    if (!font.loadFromFile("SourceCodePro-VariableFont_wght.ttf"))
    {
        std::cout << "Error Loading Font" << std::endl;
    }

    TextFactory textFactory;
    textFactory.font = &font;
    textFactory.window = &window;

    std::list<TextFragment> parsedList = *(new std::list<TextFragment>());
    NoctusParser* parser = new NoctusParser();
    parser->ParseString("This is a test string\nHello World!", &parsedList);
    parser->ParseString(" This is the second string", &parsedList);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        std::string offsetString = "";
        for (std::list<TextFragment>::iterator iterator = parsedList.begin(); iterator != parsedList.end(); iterator++) {
            offsetString = textFactory.DrawText(*iterator, offsetString);
        }
        window.display();
    }

    return 0;
}