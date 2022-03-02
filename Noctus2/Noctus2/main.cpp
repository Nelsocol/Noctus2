#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "TextFactory.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 1000), "Noctus Player");
    sf::CircleShape shape(100.f);
    sf::Font font;
    if (!font.loadFromFile("SourceCodePro-VariableFont_wght.ttf"))
    {
        std::cout << "Error Loading Font" << std::endl;
    }

    TextFactory textFactory;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        textFactory.DrawText(&window, "Okay let's see if text wrapping is working. That means adding a nice long string to test here real quick give me a moment. iuawvuwviawvlwnvijwklevweniuwcenlkwjalncjwbelubiuawnlvkjewanbwiuvk.baiwlebvlakwvjaehvabwlivbawliubwlivbwe", font);
        window.display();
    }

    return 0;
}