#ifndef SF_GAMESTARTEDWINDOW_CPP
#define SF_GAMESTARTEDWINDOW_CPP
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "ExitOne.h"
#include "latsgo.cpp"
#include "latsgoOne.cpp"
#include "latsgoWithBot.cpp"
#include "iostream"
#include "menuDuo.h"
using json = nlohmann::json;



using namespace sf;


void menuNastr(RenderWindow& window)
{

    //sf::RenderWindow nastr(sf::VideoMode(1920, 1080), "Трон");
    Image Icon;
    Icon.loadFromFile("../menu/icon.jpg");


    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;


    RectangleShape background(Vector2f(width, height));
    Texture Texture_window;
    Texture_window.loadFromFile("../menu/fon2.jpeg");
    background.setTexture(&Texture_window);


    Texture fastGame;
    Texture multyGame;
    Texture twoPlayer;
    Texture bot1;
    Texture bot2;
    Texture bot5;
    twoPlayer.loadFromFile("../menu/tp+.png");
    fastGame.loadFromFile("../menu/op+.png");
    multyGame.loadFromFile("../menu/bot+.png");
    bot1.loadFromFile("../menu/num1.png");
    bot2.loadFromFile("../menu/num2.png");
    bot5.loadFromFile("../menu/3.png");

    sf::Font font;
    font.loadFromFile("../cmake-build-debug/arial.ttf");
    sf::Text text, text1;
    text.setFont(font);
    text1.setFont(font);


    text1.setString("Select the number of bots");
    text.setString("Select game mode");

    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(width / 2 + width / 5.1, height / 4 + height / 4.8);
    text1.setPosition(width / 2 - width / 2.6, height / 4 + height / 3);


// set the character size
    text.setCharacterSize(36); // in pixels, not points!
    text1.setCharacterSize(36);

// set the color
    text.setFillColor(sf::Color::White);
    text1.setFillColor(sf::Color::White);


    bool isMenu = true;
    int menu1 = 0;

    Sprite  button1, buttonfastgame, buttonmulty, buttontwoPlayer, buttonbot1, buttonbot2, buttonbot5;
    buttontwoPlayer.setTexture(twoPlayer);

    buttonfastgame.setTexture(fastGame);
    buttonmulty.setTexture(multyGame);
    buttonbot1.setTexture(bot1);
    buttonbot2.setTexture(bot2);
    buttonbot5.setTexture(bot5);

    buttonmulty.setPosition(width / 2 - width / 2.3, height / 4 - height / 6);
    buttonfastgame.setPosition(width / 2 + width / 9.3, height / 4 + height / 3.3);
    button1.setPosition(width / 3 - width / 12.8, height / 4 + height / 4.7);
    buttonbot1.setPosition(width / 4 - width /6, height / 1.5 - height / 100);
    buttonbot2.setPosition(width / 2 - width / 3.2, height / 1.5 - height / 100);
    buttonbot5.setPosition(width / 2 - width / 4.9, height / 1.5 - height / 100);
    buttontwoPlayer.setPosition(width / 2 + width / 9.5, height / 4 - height / 6);
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return;

        }
        if (IntRect(width / 4 - width /6, height / 1.5 - height / 100, width / 4.7 - width / 8, height / 1.5 - height / 10).contains(
                Mouse::getPosition(window))) {
            buttonbot1.setColor(Color::Red);
            menu1 = 4;
        }
        if (IntRect(width / 2 - width / 3.2, height / 1.5 - height / 100, width / 4.7 - width / 8, height / 1.5 - height / 100).contains(
                Mouse::getPosition(window))) {
            buttonbot2.setColor(Color::Red);
            menu1 = 5;
        }
        if (IntRect(width / 2 - width / 4.9, height / 1.5 - height / 100, width / 4.7 - width / 8, height / 1.5 - height / 100).contains(
                Mouse::getPosition(window))) {
            buttonbot5.setColor(Color::Red);
            menu1 = 6;
        }
        if (IntRect(width / 2 + width / 9.3, height / 4 + height / 3.3, width / 4.7 + width /7.5, height / 3 + height / 80).contains(
                Mouse::getPosition(window))) {
            buttonfastgame.setColor(Color::Red);
            menu1 = 2;
        }

        if (IntRect(width / 2 - width / 2.3, height / 4 - height / 6, width / 4.7 + width /7.5, height / 3 + height / 80).contains(
                Mouse::getPosition(window))) {
            buttonmulty.setColor(Color::Red);
            menu1 = 3;
        }


        if (IntRect(width / 2 + width / 9.5, height / 4 - height / 6, width / 4.7 + width /7.5, height / 3 + height / 80).contains(
                Mouse::getPosition(window))) {
            buttontwoPlayer.setColor(Color::Red);
            menu1 = 1;
        }


        std::ifstream file("tekst.json");
        json data = json::parse(file);

        file.close();
        sf::Event event;
        while (window.pollEvent(event)) {

            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menu1 == 4) {
                    data["bot"] = 1;
                    std::cout << data;

                }
                if (menu1 == 6) {
                    data["bot"] = 3;
                }
                if (menu1 == 5) {
                    data["bot"] = 2;
                }
                std::ofstream file_close("tekst.json");
                file_close << data;
                file_close.close();

                if (menu1 == 3) {
                    std::ifstream file("tekst.json");
                    json data = json::parse(file);

                    file.close();
                    if(data["bot"] == 2){
                        latsgoWithTwoBot(window);
                    }
                    if(data["bot"] == 3){
                        latsgoWithThreeBot(window);
                    }
                    else {
                        latsgoWithBot(window);
                    }


                }
                if (menu1 == 2) {
                    latsgo1(window);


                }
                if (menu1 == 1) {

                    menuDuo(window);


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