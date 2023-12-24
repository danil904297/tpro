


#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

void exitConfirmation()
{

    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    sf::RenderWindow window(sf::VideoMode(800, 400), "Выход");
    sf::Font font;
    font.loadFromFile("../cmake-build-debug/arial.ttf");

    sf::Text text("Вы уверены, что хотите выйти?", font, 30);
    text.setPosition(10, 10);

    sf::Text confirm("Да/Нет", font, 36);

    text.setStyle(sf::Text::Bold | sf::Text::Underlined);


    text.setPosition(width / 2 + width / 4.5, height / 4 + height / 4);
    confirm.setPosition(width / 2 - width / 4.5, height / 4 + height / 4);


// set the character size
    text.setCharacterSize(36); // in pixels, not points!


// set the color
    text.setFillColor(sf::Color(255, 188, 128, 128));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (confirm.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        window.close();
                    }
                }
            }
        }

        window.clear();
        window.draw(text);
        window.draw(confirm);
        window.display();
    }
}