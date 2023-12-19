
#ifndef SF_WIN_H
#define SF_WIN_H

#include "SFML/Graphics.hpp"

int win()
{
    sf::RenderWindow window(sf::VideoMode(400, 200), "Поздравляю!");

    sf::Font font;
    font.loadFromFile("../cmake-build-debug/arial.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Win");
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(100, 100);

    text.setCharacterSize(36);
    text.setFillColor(sf::Color::Red);

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


#endif //SF_WIN_H
