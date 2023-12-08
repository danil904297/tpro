//
// Created by Администратор on 04.12.2023.
//

#ifndef SF_MENU_H
#define SF_MENU_H
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "Play.h"
#include "nastr.cpp"
using namespace sf;
void Options1()
{
    VideoMode::getDesktopMode();

    RenderWindow window(sf::VideoMode(800, 600), "Options");
    bool isMenu = true;
    window.setActive(true);
    window.setPosition(sf::Vector2i(10, 50));
    while (isMenu)
    {
        float width = VideoMode::getDesktopMode().width;
        float height = VideoMode::getDesktopMode().height;


        RectangleShape background(Vector2f(width, height));
        Texture Texture_window;
        Texture_window.loadFromFile("../menu/fomMenu.jpg");
        background.setTexture(&Texture_window);


        window.draw(background);
        window.display();
    }
}
//void Print() {
//    std::cout << "CLick!'\n";
//}


void menu(RenderWindow& window) {

    Image Icon;
    Icon.loadFromFile("../menu/icon.jpg");


    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    RectangleShape background(Vector2f(width, height));
    Texture Texture_window;
    Texture_window.loadFromFile("../menu/fomMenu.jpg");
    background.setTexture(&Texture_window);

    Texture textureClicked;
    Texture textureBase;
    Texture textureExit;
    Texture textureOptions;
    Texture textureTitul;
    textureExit.loadFromFile("../menu/exit.jpg");
    textureBase.loadFromFile("../menu/play.jpg");
    textureOptions.loadFromFile("../menu/nastr.jpg");
    textureTitul.loadFromFile("../menu/tron.jpg");
    bool isMenu = true;
    int menu1 = 0;

    textureClicked.loadFromFile("../menu/play.jpg");
    Sprite Titul, button1, button2, button3;
    button1.setTexture(textureOptions);
    button2.setTexture(textureBase);
    button3.setTexture(textureExit);
    Titul.setTexture(textureTitul);
    Titul.setPosition(width / 2 - width / 12.8, height / 10);
    button1.setPosition(width / 2 - width / 12.8, height / 4 + height / 4.7);
    button2.setPosition(width / 2 - width / 12.8, height / 4 + height / 36);
    button3.setPosition(width / 2 - width / 12.8, height / 4 + height / 2.51);
    window.setIcon(562, 1000, Icon.getPixelsPtr());
    while (isMenu) {
        Vector2u size = window.getSize();
        int width = size.x;
        int height = size.y;
        menu1 = 0;
        button1.setColor(Color::White);
        button2.setColor(Color::White);
        button3.setColor(Color::White);
        if (IntRect(width / 2 - width / 12.8, height / 4 + height / 4.7, width / 4.8, height / 10.8).contains(
                Mouse::getPosition(window))) {
            button1.setColor(Color::Red);
            menu1 = 2;
        }
        if (IntRect(width / 2 - width / 19.2, height / 4 + height / 36, width / 6.4, height / 10.8).contains(
                Mouse::getPosition(window))) {
            button2.setColor(Color::Red);
            menu1 = 1;
        }
        if (IntRect(width / 2 - width / 22, height / 4 + height / 2.51, width / 7, height / 10.8).contains(
                Mouse::getPosition(window))) {
            button3.setColor(Color::Red);
            menu1 = 3;
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 1) {
                    window.close();
                    isMenu = false;
                    play();

                }
            }
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 2) {
                    window.setActive(false);
                    nastr();
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
        window.draw(Titul);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.display();
    }
}

#endif //SF_MENU_H
