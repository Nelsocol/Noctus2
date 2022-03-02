#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <list>

#include "TextFactory.h"

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
    std::list<TextFragment> fragmentList = *(new std::list<TextFragment>());
    fragmentList.push_back(*(new TextFragment(&window, "Okay let's see if text wrapping is working. \nThat means adding a nice long string to test here real quick give me a moment. iuawvuwviawvlwnvijwklevweniuwcenlkwjalncjwbelubiuawnlvkjewanbwiuvk.baiwlebvlakwvjaehvabwlivbawliubwlivbwe", font)));
    fragmentList.push_back(*(new TextFragment(&window, " Here's the next string", font, sf::Color(255, 0, 0, 255))));
    fragmentList.push_back(*(new TextFragment(&window, " Here's a third string.\n\n", font)));
    fragmentList.push_back(*(new TextFragment(&window, " Here's a string two lines down and in green!\n\n", font, sf::Color(0, 255, 0, 255))));

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
        for (std::list<TextFragment>::iterator iterator = fragmentList.begin(); iterator != fragmentList.end(); iterator++) {
            offsetString = textFactory.DrawText(*iterator, offsetString);
        }
        window.display();
    }

    return 0;
}