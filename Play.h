//
// Created by Администратор on 07.12.2023.
//

#ifndef SF_PLAY_H
#define SF_PLAY_H
#include "SFML/Graphics.hpp"

void play()
{
    // Создание окна игры
    sf::RenderWindow window(sf::VideoMode(800, 600), "Трон");

    // Установка скорости обновления экрана
    window.setFramerateLimit(60);

    // Создание объект игрока(мотоциклов)
    sf::RectangleShape player1(sf::Vector2f(30, 30));
    player1.setFillColor(sf::Color::Red);
    player1.setPosition(100, 300);

    // Главный цикл игры
    while (window.isOpen())
    {
        // Обработка событий
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Обновление состояния игры

        // Управление игроком 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player1.move(0, -5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player1.move(0, 5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player1.move(-5, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player1.move(5, 0);


        // Отрисовка игры
        window.clear();
        window.draw(player1);
        window.display();
    }


}
#endif //SF_PLAY_H
