
//#ifndef SF_OPTIONS_H
//#define SF_OPTIONS_H
#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "ExitOne.h"

#include "global.h"
#include "external/nlohmann/json.hpp"
#include "fstream"
#include "iostream"
using json = nlohmann::json;




using namespace sf;


void menuOptions(RenderWindow &window) {


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
    textureExit.loadFromFile("../menu/save.png");
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
    int scolor = 0;



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

    window.setIcon(562, 1000, Icon.getPixelsPtr());
    while (isMenu) {


        Vector2u size = window.getSize();
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
                Mouse::getPosition(window))) {
            buttonfastgame.setColor(Color::Red);
            menu1 = 1;
        }

        if (IntRect(width / 2 - width / 2.5, height / 4 - height / 25, width / 2 - width / 2.5, height / 4 - height / 15).contains(
                Mouse::getPosition(window))) {
            buttonmulty.setColor(Color::Red);
            menu1 = 4;
        }

        if (IntRect(width / 2 - width / 7.4, height / 4 + height / 2.2, width / 4.7, height / 6.8).contains(
                Mouse::getPosition(window))) {
            button3.setColor(Color::Red);
            menu1 = 3;

        }

        if (IntRect(width / 4 + width / 1.93, height / 4 - height / 18.3, width / 80 + width / 33, height / 6 - height/11).contains(
                Mouse::getPosition(window))) {
            buttonwhite.setColor(Color::Green);
            check_color = 1;
            scolor = 1;
        }

        if (IntRect(width / 4 + width / 2.14, height / 4 - height / 18.3, width / 80 + width / 33, height / 6 - height/11).contains(
                Mouse::getPosition(window))) {
            buttonblue.setColor(Color::Red);
            check_color = 2;
            scolor = 2;
        }


        if (IntRect(width / 3.5 + width / 1.87, height / 4 - height / 18.3, width / 80 + width / 33, height / 6 - height/11).contains(
                Mouse::getPosition(window))) {
            buttonred.setColor(Color::Black);
            check_color = 3;
            scolor = 3;
        }
        if (IntRect(width / 4 + width / 1.93, height / 5 + height / 12, width / 80 + width / 33, height / 6 - height/11).contains(
                Mouse::getPosition(window))) {
            buttonpink.setColor(Color::Red);
            check_color = 3;
            scolor = 4;
        }

        if (IntRect(width / 4 + width / 1.93, height / 4 - height / 18.3, width / 80 + width / 33, height / 6 - height/11).contains(
                Mouse::getPosition(window))) {
            buttonwhite.setColor(Color::Green);
            check_color = 1;
            scolor = 1;
        }




        bool isEnteringName = false;
        std::ifstream file("tekst.json");
        json data = json::parse(file);

        file.close();
        sf::Event event;
        while (window.pollEvent(event)) {

            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 4) {
                    //win(window);
                    qwe = 0;
                    data["qwe"] = 0;
                    std::cout << data;
                }
                if (scolor == 1) {

                    check_color = 1;
                    data["Color"] = 1;
                }
                if (scolor == 2) {
                    check_color = 2;
                    data["Color"] = 2;
                }
                if (scolor == 3) {
                    check_color = 3;
                    data["Color"] = 3;
                }
                if (scolor == 4) {
                    check_color = 0;
                    data["Color"] = 4;

                }
                if (menu1 == 2) {
                    qwe = 1;
                    data["qwe"] = 1;
                    std::cout << qwe;
                }
                std::ofstream file_close("tekst.json");
                file_close << data;
                file_close.close();

            }

            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 3) {
                    return;
                }
            }
            if (event.type == sf::Event::Closed) window.close();
        }

        window.draw(background);
        window.draw(text);
        window.draw(text1);
        window.draw(color);
        window.draw(button1);
        window.draw(buttoncircle);
        window.draw(buttonfastgame);
        window.draw(buttonmulty);
        window.draw(buttonblue);
        window.draw(buttonred);
        window.draw(buttonwhite);
        window.draw(buttonpink);
        window.draw(button3);
        window.display();
    }
    return;
}
//#endif //SF_OPTIONS_H