
#ifndef SF_OPTIONS_H
#define SF_OPTIONS_H
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "ExitOne.h"
#include "win.h"




using namespace sf;


int menuOptions() {

    sf::RenderWindow Options(sf::VideoMode(1920, 1080), "Трон");
    Image Icon;
    Icon.loadFromFile("../menu/icon.jpg");


    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    RectangleShape background(Vector2f(width, height));
    Texture Texture_window;
    Texture_window.loadFromFile("../menu/fon.jpeg");
    background.setTexture(&Texture_window);


    Texture textureBase;
    Texture textureExit;
    Texture fastGame;
    Texture multyGame;
    Texture blue;
    Texture red;
    Texture white;
    Texture pink;
    Texture circle;
    fastGame.loadFromFile("../menu/strelki.png");
    multyGame.loadFromFile("../menu/wasd++.png");
    textureExit.loadFromFile("../menu/exit2.png");
    blue.loadFromFile("../menu/blue.png");
    red.loadFromFile("../menu/red.png");
    white.loadFromFile("../menu/green.png");
    pink.loadFromFile("../menu/p!nk.png");
    circle.loadFromFile("../menu/ring+.png");



    sf::Font font;
    font.loadFromFile("../cmake-build-debug/arial.ttf");
    std::string name;
    sf::Text text, text1, color;
    text.setFont(font);
    text1.setFont(font);
    color.setFont(font);

    color.setString("Select color");
    text.setString("Enter your name");
    text1.setString("Select control");

    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    color.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(width / 2 + width / 4.5, height / 4 + height / 2.3);
    text1.setPosition(width / 2 - width / 2.3, height / 4 + height / 4);
    color.setPosition(width / 2 + width / 4.2, height / 8 + height / 80);



// set the character size
    text.setCharacterSize(36); // in pixels, not points!
    text1.setCharacterSize(36);
    color.setCharacterSize(36);

// set the color
    text.setFillColor(sf::Color::Red);
    text1.setFillColor(sf::Color::Red);
    color.setFillColor(sf::Color::Red);


    bool isMenu = true;
    int menu1 = 0;


    //textureClicked.loadFromFile("../menu/play.jpg");
    Sprite  button1, button3, buttonfastgame, buttonmulty,  buttontext, buttonblue, buttonred, buttonwhite, buttonpink, buttoncircle;


    button3.setTexture(textureExit);
    buttonfastgame.setTexture(fastGame);
    buttonmulty.setTexture(multyGame);
    buttonblue.setTexture(blue);
    buttonred.setTexture(red);
    buttonwhite.setTexture(white);
    buttonpink.setTexture(pink);
    buttoncircle.setTexture(circle);

    buttonmulty.setPosition(width / 4 - width / 4.5, height / 4 - height / 25);
    buttonfastgame.setPosition(width / 4 - width / 4.5, height / 4 + height / 3);
    button3.setPosition(width / 2 - width / 7.4, height / 4 + height / 2.2);
    buttonwhite.setPosition(width / 4 + width / 1.93, height / 4 - height / 18.3);
    buttonred.setPosition(width / 3.5 + width / 1.87, height / 4 - height / 18.3);
    buttonblue.setPosition(width / 4 + width / 2.14, height / 4 - height / 18.3);
    buttonpink.setPosition(width / 4 + width / 1.93, height / 5 + height / 12);
    buttoncircle.setPosition(width / 3 + width / 3.15, height / 4 - height / 4);

    Options.setIcon(562, 1000, Icon.getPixelsPtr());
    while (isMenu) {


        Vector2u size = Options.getSize();
        int width = size.x;
        int height = size.y;
        menu1 = 0;
        //button1.setColor(Color(255, 188, 128, 128));

        button3.setColor(Color(255, 255, 255, 128));
        buttonmulty.setColor(sf::Color::White);
        buttonfastgame.setColor(sf::Color::White);
        buttonblue.setColor(sf::Color::White);
        buttonred.setColor(sf::Color::White);
        buttonwhite.setColor(sf::Color::White);
        buttonpink.setColor(sf::Color::White);




        if (IntRect(width / 2 - width / 2.3, height / 4 + height / 4, width / 2 - width / 2.8, height / 4 + height / 3).contains(
                Mouse::getPosition(Options))) {
            buttonfastgame.setColor(Color::Red);
            menu1 = 1;
        }

        if (IntRect(width / 2 - width / 2.5, height / 4 - height / 25, width / 2 - width / 2.5, height / 4 - height / 15).contains(
                Mouse::getPosition(Options))) {
            buttonmulty.setColor(Color::Red);
            menu1 = 4;
        }

        if (IntRect(width / 2 - width / 7.4, height / 4 + height / 2.2, width / 4.7, height / 6.8).contains(
                Mouse::getPosition(Options))) {
            button3.setColor(Color::Red);
            menu1 = 3;

        }

        if (IntRect(width / 3 + width / 4.5, height / 4 - height / 25, width / 140 + width / 14, height / 6).contains(
                Mouse::getPosition(Options))) {
            buttonwhite.setColor(Color::Green);
            menu1 = 3;
        }

        if (IntRect(width / 4 + width / 2.3, height / 4 - height / 25, width / 120 + width / 14, height / 6).contains(
                Mouse::getPosition(Options))) {
            buttonblue.setColor(Color::Red);
            menu1 = 3;
        }

        if (IntRect(width / 3.5 + width / 1.9, height / 4 - height / 25, width / 100 + width / 14, height / 6).contains(
                Mouse::getPosition(Options))) {
            buttonred.setColor(Color::Black);
            menu1 = 3;
        }
        if (IntRect(width / 3.5 + width / 1.9, height / 4 - height / 20, width / 100 + width / 14, height / 6).contains(
                Mouse::getPosition(Options))) {
            buttonpink.setColor(Color::Red);
            menu1 = 1;
        }




        bool isEnteringName = false;

        sf::Event event;
        while (Options.pollEvent(event)) {
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 1) {

                    win();

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
                    if(ExitOne()==1) {Options.close(); return 1;}
                }
            }
            if (event.type == sf::Event::Closed)
                Options.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
            {
                if (isEnteringName)
                {
                    isEnteringName = false;
                }
                else
                {
                    isEnteringName = true;
                    name.clear();
                    text.setString("");
                }
            }

            if (event.type == sf::Event::TextEntered && isEnteringName)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == '\b' && !name.empty())
                    {
                        name.pop_back();
                    }
                    else if (event.text.unicode != '\b')
                    {
                        name += event.text.unicode;
                    }

                    text.setString(name);
                }
            }
        }



        Options.draw(background);
        Options.draw(text);
        Options.draw(text1);
        Options.draw(color);
        Options.draw(button1);
        Options.draw(buttoncircle);
        Options.draw(buttonfastgame);
        Options.draw(buttonmulty);
        Options.draw(buttonblue);
        Options.draw(buttonred);
        Options.draw(buttonwhite);
        Options.draw(buttonpink);
        Options.draw(button3);
        Options.display();
    }
    return 0;
}
#endif //SF_OPTIONS_H
