//
// Created by Администратор on 19.12.2023.
//

#include "SFML/Graphics.hpp"
#include <iostream>

void name1()
{
    std::string keyEnteredMessage("Name:");

    sf::Font font;
    if(!font.loadFromFile("../cmake-build-debug/arial.ttf")){
        return;
    }


    sf::Text textKey("Enter your name",font,36);

    textKey.setStyle(sf::Text::Italic);
    textKey.setPosition(20,50);

    sf::RenderWindow name(sf::VideoMode(600, 600), "Name");


    while (name.isOpen())
    {
        sf::Event event;

        while (name.pollEvent(event))
        {

            switch(event.type)
            {
                case sf::Event::Closed:{
                    name.close();
                    break;
                }
                case sf::Event::TextEntered:{
                    keyEnteredMessage += event.text.unicode;
                    textKey.setString(keyEnteredMessage);

                }


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                name.close();
            }
        }

        name.clear();

        name.draw(textKey);
        name.display();
    }

    return;
}
