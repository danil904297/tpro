
#ifndef SF_OPTIONS_H
#define SF_OPTIONS_H
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

using namespace sf;


void menuOptions(RenderWindow& window) {

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
    Texture multyGame;
    Texture blue;
    Texture red;
    Texture white;
    fastGame.loadFromFile("../menu/strelki.png");
    multyGame.loadFromFile("../menu/wsad.jpg");
    textureExit.loadFromFile("../menu/exit.jpg");
    blue.loadFromFile("../menu/blue.png");
    red.loadFromFile("../menu/red.png");
    white.loadFromFile("../menu/whete.png");



    sf::Font font;
    font.loadFromFile("../cmake-build-debug/arial.ttf");
    sf::Text text, text1;
    text.setFont(font);
    text1.setFont(font);


    text.setString("Enter your name");
    text1.setString("Select control");

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
    Sprite  button1, button2, button3, buttonfastgame, buttonmulty,  buttontext, buttonblue, buttonred, buttonwhite;


    button3.setTexture(textureExit);
    buttonfastgame.setTexture(fastGame);
    buttonmulty.setTexture(multyGame);
    buttonblue.setTexture(blue);
    buttonred.setTexture(red);
    buttonwhite.setTexture(white);

    buttonmulty.setPosition(width / 2 - width / 2.3, height / 4 - height / 25);
    buttonfastgame.setPosition(width / 2 - width / 2.3, height / 4 + height / 3);
    button1.setPosition(width / 3 - width / 12.8, height / 4 + height / 4.7);
    button3.setPosition(width / 2 - width / 12.8, height / 4 + height / 2);
    buttonblue.setPosition(width / 3 + width / 4.5, height / 4 - height / 25);
    buttonred.setPosition(width / 3.5 + width / 1.9, height / 4 - height / 25);
    buttonwhite.setPosition(width / 4 + width / 2.3, height / 4 - height / 25);
    window.setIcon(562, 1000, Icon.getPixelsPtr());
    while (isMenu) {
        Vector2u size = window.getSize();
        int width = size.x;
        int height = size.y;
        menu1 = 0;
        button1.setColor(Color(255, 188, 128, 128));

        button3.setColor(Color(255, 255, 255, 128));
        buttonmulty.setColor(sf::Color::Red);
        buttonfastgame.setColor(sf::Color::Red);
        buttonblue.setColor(sf::Color::White);
        buttonred.setColor(sf::Color::White);
        buttonwhite.setColor(sf::Color::White);




        if (IntRect(width / 2 - width / 2.3, height / 4 + height / 4, width / 2 - width / 2.8, height / 4 + height / 3).contains(
                Mouse::getPosition(window))) {
            buttonfastgame.setColor(Color::White);
            menu1 = 2;
        }

        if (IntRect(width / 2 - width / 2.5, height / 4 - height / 25, width / 2 - width / 2.5, height / 4 - height / 15).contains(
                Mouse::getPosition(window))) {
            buttonmulty.setColor(Color::White);
            menu1 = 4;
        }

        if (IntRect(width / 2 - width / 12.8, height / 4 + height / 2, width / 7, height / 10.8).contains(
                Mouse::getPosition(window))) {
            button3.setColor(Color::White);
            menu1 = 3;
        }

        if (IntRect(width / 3 + width / 4.5, height / 4 - height / 25, width / 3 + width / 2.7, height / 4).contains(
                Mouse::getPosition(window))) {
            buttonblue.setColor(Color::Red);
            menu1 = 3;
        }





        sf::Event event;
        while (window.pollEvent(event)) {
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 1) {



                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 2) {


                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 4) {


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
        window.draw(buttonmulty);
        window.draw(buttonblue);
        window.draw(buttonred);
        window.draw(buttonwhite);
        window.draw(button3);
        window.display();
    }
}
#endif //SF_OPTIONS_H
