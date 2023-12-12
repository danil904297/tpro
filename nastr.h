//
// Created by Администратор on 07.12.2023.
//

#ifndef SF_GAMESTARTEDWINDOW_CPP
#define SF_GAMESTARTEDWINDOW_CPP
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
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


    Texture textureBase;
    Texture textureExit;
    Texture fastGame;

    fastGame.loadFromFile("../menu/fastgame.png");
    textureExit.loadFromFile("../menu/exit.jpg");
    textureBase.loadFromFile("../menu/startgame.jpg");


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


    //textureClicked.loadFromFile("../menu/play.jpg");
    Sprite  button1, button2, button3, buttonfastgame, buttontext;

    button2.setTexture(textureBase);
    button3.setTexture(textureExit);
    buttonfastgame.setTexture(fastGame);
    buttontext.setPosition(width/7, height/5);
    buttonfastgame.setPosition(width / 2 + width / 4.5, height / 4 + height / 5);
    //button1.setPosition(width / 3 - width / 12.8, height / 4 + height / 4.7);
    button2.setPosition(width / 2 - width / 45 , height / 4 - height /5);
    button3.setPosition(width / 2 - width / 12.8, height / 4 + height / 2);
    window.setIcon(562, 1000, Icon.getPixelsPtr());
    while (isMenu) {
        Vector2u size = window.getSize();
        int width = size.x;
        int height = size.y;
        menu1 = 0;
        button1.setColor(Color(255, 188, 128, 128));
        button2.setColor(Color(255, 255, 255, 128));
        button3.setColor(Color(255, 255, 255, 128));
        buttontext.setColor(sf::Color::Red);
        buttonfastgame.setColor(sf::Color::Red);
        if (IntRect(width / 3 - width / 12.8, height / 4 + height / 4.7, width / 4.8, height / 10.8).contains(
                Mouse::getPosition(window))) {
            buttonfastgame.setColor(Color::White);
            menu1 = 2;
        }
        if (IntRect(width / 2 - width / 45 , height / 4 - height /5, width / 6.4, height / 10.8).contains(
                Mouse::getPosition(window))) {
            button2.setColor(Color::White);
            menu1 = 1;
        }
        if (IntRect(width / 2 - width / 12.8, height / 4 + height / 2, width / 7, height / 10.8).contains(
                Mouse::getPosition(window))) {
            button3.setColor(Color::White);
            menu1 = 3;
        }
//        if (IntRect(width / 7, height / 5,width / 7,59).contains(
//                Mouse::getPosition(window))) {
//            buttontext.setColor(Color::Green);
//        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 1) {

                    play();

                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 2) {
                    window.setActive(false);

                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 3) {
                    window.close();
                    isMenu = false;
                }
            }
        }



        window.draw(background);
        window.draw(text);
        window.draw(text1);
        window.draw(button1);
        window.draw(buttonfastgame);
        window.draw(button2);
        window.draw(button3);
        window.display();
    }
}


#endif //SF_GAMESTARTEDWINDOW_CPP
