//
// Created by Администратор on 21.12.2023.
//

#ifndef SF_MENUDUO_H
#define SF_MENUDUO_H

#ifndef SF_OPTIONS_H
#define SF_OPTIONS_H
#include "SFML/Graphics.hpp"

#include <string>
#include "ExitOne.h"
#include "win.h"
#include "name.cpp"
#include "global.h"
#include "external/nlohmann/json.hpp"
#include "fstream"
#include "iostream"
#include "latsgo.cpp"
using json = nlohmann::json;




using namespace sf;


void menuDuo(RenderWindow &window) {


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

    Texture blue;
    Texture red;
    Texture white;
    Texture pink;
    Texture circle;

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

    buttonblue.setTexture(blue);
    buttonred.setTexture(red);
    buttonwhite.setTexture(white);
    buttonpink.setTexture(pink);
    buttoncircle.setTexture(circle);



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

        buttonblue.setColor(sf::Color::White);
        buttonred.setColor(sf::Color::White);
        buttonwhite.setColor(sf::Color::White);
        buttonpink.setColor(sf::Color::White);






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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                return;

            }
            if (Mouse::isButtonPressed(Mouse::Left)) {

                if (scolor == 1) {

                    check_color = 1;
                    data["Color1"] = 1;
                }
                if (scolor == 2) {
                    check_color = 2;
                    data["Color1"] = 2;
                }
                if (scolor == 3) {
                    check_color = 3;
                    data["Color1"] = 3;
                }
                if (scolor == 4) {
                    check_color = 0;
                    data["Color1"] = 4;

                }

                std::ofstream file_close("tekst.json");
                file_close << data;
                file_close.close();

            }

            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 3) {
                    latsgo(window);
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

        window.draw(buttonblue);
        window.draw(buttonred);
        window.draw(buttonwhite);
        window.draw(buttonpink);
        window.draw(button3);
        window.display();
    }
    return;
}
#endif //SF_OPTIONS_H

#endif //SF_MENUDUO_H
