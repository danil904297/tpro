//
// Created by Администратор on 07.12.2023.
//

#ifndef SF_GAMESTARTEDWINDOW_CPP
#define SF_GAMESTARTEDWINDOW_CPP
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "latsgo.cpp"
#include "latsgoOne.cpp"


using namespace sf;


void menuNastr(RenderWindow& window) {

    Image Icon;
    Icon.loadFromFile("../menu/icon.jpg");


    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    RectangleShape background(Vector2f(width, height));
    Texture Texture_window;
    Texture_window.loadFromFile("../menu/fon.png");
    background.setTexture(&Texture_window);


    Texture fastGame;
    Texture multyGame;
    Texture twoPlayer;
    Texture bot1;
    Texture bot2;
    Texture bot5;
    twoPlayer.loadFromFile("../menu/duo.png");
    fastGame.loadFromFile("../menu/fastgame.png");
    multyGame.loadFromFile("../menu/multygame.jpg");
    bot1.loadFromFile("../menu/1.png");
    bot2.loadFromFile("../menu/2.png");
    bot5.loadFromFile("../menu/5.png");

    sf::Font font;
    font.loadFromFile("../cmake-build-debug/arial.ttf");
    sf::Text text, text1;
    text.setFont(font);
    text1.setFont(font);


    text.setString("Select the number of bots");
    text1.setString("Select game mode");

    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(width / 2 + width / 4.5, height / 4 + height / 4);
    text1.setPosition(width / 2 - width / 2.3, height / 4 + height / 4);


// set the character size
    text.setCharacterSize(36); // in pixels, not points!
    text1.setCharacterSize(36);

// set the color
    text.setFillColor(sf::Color(255, 188, 128, 128));
    text1.setFillColor(sf::Color::Red);


    bool isMenu = true;
    int menu1 = 0;

    Sprite  button1, buttonfastgame, buttonmulty, buttontwoPlayer, buttonbot1, buttonbot2, buttonbot5;
    buttontwoPlayer.setTexture(twoPlayer);

    buttonfastgame.setTexture(fastGame);
    buttonmulty.setTexture(multyGame);
    buttonbot1.setTexture(bot1);
    buttonbot2.setTexture(bot2);
    buttonbot5.setTexture(bot5);

    buttonmulty.setPosition(width / 2 - width / 2.3, height / 4 - height / 3);
    buttonfastgame.setPosition(width / 2 - width / 2.3, height / 4 + height / 3);
    button1.setPosition(width / 3 - width / 12.8, height / 4 + height / 4.7);
    buttonbot1.setPosition(width / 1.9 + width / 8, height / 1.5 - height / 100);
    buttonbot2.setPosition(width / 1.6 + width / 7.5, height / 1.5 - height / 100);
    buttonbot5.setPosition(width / 1.4 + width / 7, height / 1.5 - height / 100);
    buttontwoPlayer.setPosition(width / 2 + width / 7, height / 4 - height / 6);
    window.setIcon(562, 1000, Icon.getPixelsPtr());
    while (isMenu) {
        Vector2u size = window.getSize();
        int width = size.x;
        int height = size.y;
        menu1 = 0;
        button1.setColor(Color(255, 188, 128, 128));
        buttonmulty.setColor(sf::Color::White);
        buttonfastgame.setColor(sf::Color::White);
        buttontwoPlayer.setColor(sf::Color::White);
        buttonbot1.setColor(sf::Color::White);
        buttonbot2.setColor(sf::Color::White);
        buttonbot5.setColor(sf::Color::White);


        if (IntRect(width / 1.9 + width / 8, height / 1.5 - height / 100, width / 4.7 - width / 8, height / 1.5 - height / 100).contains(
                Mouse::getPosition(window))) {
            buttonbot1.setColor(Color::Red);
            menu1 = 4;
        }
        if (IntRect(width / 1.6 + width / 7.5, height / 1.5 - height / 100, width / 4.7 - width / 8, height / 1.5 - height / 100).contains(
                Mouse::getPosition(window))) {
            buttonbot2.setColor(Color::Red);
            menu1 = 5;
        }
        if (IntRect(width / 1.4 + width / 7, height / 1.5 - height / 100, width / 4.7 - width / 8, height / 1.5 - height / 100).contains(
                Mouse::getPosition(window))) {
            buttonbot5.setColor(Color::Red);
            menu1 = 6;
        }
        if (IntRect(width / 2 - width / 2.3, height / 4 + height / 4, width / 4, height /3).contains(
                Mouse::getPosition(window))) {
            buttonfastgame.setColor(Color::Red);
            menu1 = 2;
        }

        if (IntRect(width / 2 - width / 2.3, height / 4 - height / 3, width / 2, height /3).contains(
                Mouse::getPosition(window))) {
            buttonmulty.setColor(Color::Red);
            menu1 = 3;
        }


        if (IntRect(width / 2 + width / 7, height / 4 - height / 6, width / 2, height /3).contains(
                Mouse::getPosition(window))) {
            buttontwoPlayer.setColor(Color::Red);
            menu1 = 1;
        }


        sf::Event event;
        while (window.pollEvent(event)) {
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 1) {

                    latsgo();

                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 2) {
                    latsgo1();

                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 3) {


                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 4) {

                    latsgo();

                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 5) {

                    latsgo();

                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 6) {

                    latsgo();

                }
            }


        }



        window.draw(background);
        window.draw(text);
        window.draw(text1);
        window.draw(button1);
        window.draw(buttonfastgame);
        window.draw(buttonmulty);
        window.draw(buttontwoPlayer);
        window.draw(buttonbot1);
        window.draw(buttonbot2);
        window.draw(buttonbot5);


        window.display();
    }
}


#endif //SF_GAMESTARTEDWINDOW_CPP
