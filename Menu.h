#ifndef SF_MENU_H
#define SF_MENU_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "nastr.h"
#include "options.h"
#include "exitConfirmation.h"
#include "exit.h"
using namespace sf;


void menu(RenderWindow& window) {

    Image Icon, exit;
    Icon.loadFromFile("../menu/icon.jpg");
    exit.loadFromFile("../menu/exit.jpg");
    exit.createMaskFromColor(Color(255, 0,0));

    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    RectangleShape background(Vector2f(width, height));
    Texture Texture_window;
    Texture_window.loadFromFile("../menu/preview.jpg");
    background.setTexture(&Texture_window);

    Texture textureClicked;
    Texture textureBase;
    Texture textureExit;
    Texture textureOptions;
    Texture textureTitul;
    textureExit.loadFromFile("../menu/exit.png");
    textureBase.loadFromFile("../menu/Start.png");
    textureOptions.loadFromFile("../menu/opt.png");
    textureTitul.loadFromFile("../menu/tron.png");
    bool isMenu = true;
    int menu1 = 0;

    textureClicked.loadFromFile("../menu/play.jpg");
    Sprite Titul, button1, button2, button3;
    button1.setTexture(textureOptions);
    button2.setTexture(textureBase);
    button3.setTexture(textureExit);
    Titul.setTexture(textureTitul);
    Titul.setPosition(width / 2 - width / 2.5, height / 10 - height / 20);
    button1.setPosition(width / 2 - width / 2.5, height / 4 + height / 4.7);
    button2.setPosition(width / 2 - width / 2.5, height / 4 + height / 36);
    button3.setPosition(width / 2 - width / 2.5, height / 4 + height / 2.51);
    window.setIcon(562, 1000, Icon.getPixelsPtr());
    while (isMenu) {
        Vector2u size = window.getSize();
        int width = size.x;
        int height = size.y;
        menu1 = 0;
        button1.setColor(Color::White);
        button2.setColor(Color::White);
        button3.setColor(Color::White);

        if (IntRect(width / 2 - width / 2.5, height / 4 + height / 4.7, width / 4, height / 6).contains(
                Mouse::getPosition(window))) {
            button1.setColor(Color::Red);
            menu1 = 2;
        }
        if (IntRect(width / 2 - width / 2.5, height / 4 + height / 36, width / 4.5, height / 6).contains(
                Mouse::getPosition(window))) {
            button2.setColor(Color::Red);
            menu1 = 1;
        }
        if (IntRect(width / 2 - width / 2.5, height / 4 + height / 2.51, width / 4, height / 6).contains(
                Mouse::getPosition(window))) {
            button3.setColor(Color::Red);
            menu1 = 3;
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 1) {

                    menuNastr(window);



                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 2) {
                    menuOptions(window);



                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 3) {
                    Exit(window);



                }
            }
        }

        window.draw(background);
        window.draw(Titul);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.display();
    }
}

#endif //SF_MENU_H
