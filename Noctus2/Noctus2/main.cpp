#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 1000), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::Font font;
    if (!font.loadFromFile("SourceCodePro-VariableFont_wght.ttf"))
    {
        std::cout << "Error Loading Font" << std::endl;
    }

    sf::Text text;
    text.setFont(font); 
    text.setString("Hello World.");
    text.setCharacterSize(15); 
    text.setFillColor(sf::Color(232, 232, 237, 255));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}