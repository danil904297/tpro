//
// Created by Администратор on 07.12.2023.
//

#ifndef SF_GAMESTARTEDWINDOW_CPP
#define SF_GAMESTARTEDWINDOW_CPP
#include "SFML/Graphics.hpp"
#include <iostream>



void nastr() {

    float width = sf::VideoMode::getDesktopMode().width;
    float height = sf::VideoMode::getDesktopMode().height;
    // Создание окна с размерами 800x600 и названием "Menu"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu");

    // Установка цвета фона окна - белый
    window.clear(sf::Color::Black);

    // Создание текста для заголовка меню
    sf::Text title;
    // Загрузка шрифта из файла "arial.ttf"
    sf::Font font;
    font.loadFromFile("../font/Xenotroncyrillic.ttf");
    // Установка шрифта и размера текста
    title.setFont(font);
    title.setCharacterSize(50);
    // Установка позиции текста по центру окна
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);
    // Установка текстуры текста
    title.setString("Menu");

    // Создание текста для ввода имени
    sf::Text nameText;
    nameText.setFont(font);
    nameText.setCharacterSize(30);
    // Установка позиции текста
    nameText.setPosition(100, 200);
    // Установка текстуры текста
    nameText.setString("Name:");

    // Создание поля для ввода имени
    sf::RectangleShape nameBox(sf::Vector2f(200, 40));
    // Установка позиции поля
    nameBox.setPosition(250, 200);
    // Установка цвета поля - белый
    nameBox.setFillColor(sf::Color::Blue);

    // Создание текста для выбора цвета
    sf::Text colorText;
    colorText.setFont(font);
    colorText.setCharacterSize(30);
    // Установка позиции текста
    colorText.setPosition(100, 300);
    // Установка текстуры текста
    colorText.setString("Color:");

    // Создание кнопок для выбора цвета
    sf::RectangleShape blueButton(sf::Vector2f(50, 50));
    // Установка позиции кнопки
    blueButton.setPosition(250, 300);
    // Установка цвета кнопки - синий
    blueButton.setFillColor(sf::Color::Blue);

    sf::RectangleShape whiteButton(sf::Vector2f(50, 50));
    whiteButton.setPosition(350, 300);
    whiteButton.setFillColor(sf::Color::White);

    sf::RectangleShape redButton(sf::Vector2f(50, 50));
    redButton.setPosition(450, 300);
    redButton.setFillColor(sf::Color::Red);

    //sf::RectangleShape Play(sf::Vector2f(50, 50));
    sf::Texture texturePlay;
    texturePlay.loadFromFile("../menu/play.jpg");


    sf::Sprite Play;
    Play.setTexture(texturePlay);
    Play.setPosition(width / 2 - width / 12.8, height / 10);
    // Создание текста для кнопки "Play"
    //sf::Text playText;

    // Установка позиции play



    // Главный цикл приложения, который выполняется, пока открыто окно
    while (window.isOpen()) {
        // Обработка событий в цикле
        sf::Event event;
        while (window.pollEvent(event)) {
            // Проверка типа события - закрытие окна
            if (event.type == sf::Event::Closed)
                window.close();
            // Проверка типа события - нажатие на кнопку
            if (event.type == sf::Event::MouseButtonPressed) {
                // Получение координат клика мыши
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                // Проверка, был ли клик на кнопке "Play"
                if (mouseX >= Play.getPosition().x ||
                    mouseX <= Play.getPosition().x + Play.getGlobalBounds().width ||
                    mouseY >= Play.getPosition().y ||
                    mouseY <= Play.getPosition().y + Play.getGlobalBounds().height) {

                    if (blueButton.getFillColor() == sf::Color::Blue){}

                    else if (whiteButton.getFillColor() == sf::Color::White){}

                    else if (redButton.getFillColor() == sf::Color::Red) {}

                }
            }
        }

        // Обработка событий клавиатуры
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            // Закрытие окна при нажатии на клавишу Esc
            window.close();

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            // Изменение цвета кнопки на синий при нажатии на клавишу B
            blueButton.setFillColor(sf::Color::Blue);
            whiteButton.setFillColor(sf::Color::White);
            redButton.setFillColor(sf::Color::White);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            // Изменение цвета кнопки на белый при нажатии на клавишу W
            blueButton.setFillColor(sf::Color::White);
            whiteButton.setFillColor(sf::Color::White);
            redButton.setFillColor(sf::Color::White);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            // Изменение цвета кнопки на красный при нажатии на клавишу R
            blueButton.setFillColor(sf::Color::White);
            whiteButton.setFillColor(sf::Color::White);
            redButton.setFillColor(sf::Color::Red);
        }

        // Отрисовка элементов меню на окне
        window.draw(title);
        window.draw(nameText);
        window.draw(nameBox);
        window.draw(colorText);
        window.draw(blueButton);
        window.draw(whiteButton);
        window.draw(redButton);
        window.draw(Play);

        // Обновление окна
        window.display();
    }


#endif //SF_GAMESTARTEDWINDOW_CPP
}