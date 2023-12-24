//
// Created by Администратор on 17.12.2023.
//

#ifndef SF_ESCAPE_H
#define SF_ESCAPE_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "ExitOne.h"



using  namespace sf;

int Escape(RenderWindow& window)
{

    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;
    Color buttons_color = Color::Black, buttons_chosen = Color::Red;


    int escape_width = 1000, escape_height = 500;
    RectangleShape EscapeShape;
    Texture Texture_window;
    Texture_window.loadFromFile("../menu/fona.jpg");
    EscapeShape.setTexture(&Texture_window);
    EscapeShape.setPosition(Vector2f(VideoMode::getDesktopMode().width/2 - escape_width/2, VideoMode::getDesktopMode().height/2 - escape_height/2));
    EscapeShape.setSize(Vector2f(escape_width, escape_height));
    EscapeShape.setPosition(Vector2f(VideoMode::getDesktopMode().width/2 - escape_width/2, VideoMode::getDesktopMode().height/2 - escape_height/2));


    sf::Font font;
    if (!font.loadFromFile("../cmake-build-debug/arial.ttf")) exit(3);

    sf::Text pause_text("Pause", font, 75);
    pause_text.setFillColor(Color::Black);
    pause_text.setPosition(EscapeShape.getPosition().x + (EscapeShape.getLocalBounds().width - pause_text.getLocalBounds().width)/2, EscapeShape.getPosition().y + 40);

    sf::Text exit("Exit", font, 65);
    exit.setFillColor(buttons_color);
    exit.setPosition(EscapeShape.getPosition().x + (EscapeShape.getLocalBounds().width - pause_text.getLocalBounds().width)/2, EscapeShape.getPosition().y + 320);

    sf::Text start_again("Start again", font, 65);
    start_again.setFillColor(buttons_chosen);
    start_again.setPosition(EscapeShape.getPosition().x + (EscapeShape.getLocalBounds().width - pause_text.getLocalBounds().width)/2, EscapeShape.getPosition().y +150);


    sf::Text Continue("Continue", font, 65);
    Continue.setFillColor(buttons_color);
    Continue.setPosition(EscapeShape.getPosition().x + (EscapeShape.getLocalBounds().width - pause_text.getLocalBounds().width)/2, EscapeShape.getPosition().y +230);

    int escape_selected = 1;

    while (window.isOpen())
    {
        Event event_exit;
        while (window.pollEvent(event_exit))
        {
            if (event_exit.type == Event::KeyReleased)
            {
                if (event_exit.key.code == Keyboard::Escape) {
                    //return 3;
                }
                if(event_exit.type == Event::Closed) window.close();
            }

            if(IntRect(exit.getPosition().x, exit.getPosition().y, exit.getLocalBounds().width * 1.5,
                       exit.getLocalBounds().height + exit.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {escape_selected = 0;}

            else if(IntRect(start_again.getPosition().x, start_again.getPosition().y, start_again.getLocalBounds().width * 3,
                            start_again.getLocalBounds().height + start_again.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {escape_selected = 1;}
            else if(IntRect(Continue.getPosition().x, Continue.getPosition().y, Continue.getLocalBounds().width * 2.5,
                            Continue.getLocalBounds().height + Continue.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {escape_selected = 2;}

            else if (event_exit.type == Event::KeyPressed)
            {
                if(event_exit.key.code == Keyboard::PageDown) ++escape_selected %= 2;
                if(event_exit.key.code == Keyboard::PageUp) {if(escape_selected==0) {escape_selected = 1; escape_selected = 2;} else --escape_selected %=2;}
            }

            if (escape_selected == 0 && IntRect(exit.getPosition().x, exit.getPosition().y, exit.getLocalBounds().width * 1.5,
                                              exit.getLocalBounds().height + exit.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {
                if(event_exit.key.code == Keyboard::Enter || Mouse::isButtonPressed(Mouse::Left))
                {
                    ExitOne(window);
                    if (ExitOne(window) == 1) return 1;
                    else return 3;

                }
            } else if (escape_selected == 1 && IntRect(start_again.getPosition().x, start_again.getPosition().y, start_again.getLocalBounds().width * 1.5,
                                                     start_again.getLocalBounds().height + start_again.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {
                if(event_exit.key.code == Keyboard::Enter || Mouse::isButtonPressed(Mouse::Left))
                {

                    return 2;
                }
            } else if (escape_selected == 2 && IntRect(Continue.getPosition().x, Continue.getPosition().y, Continue.getLocalBounds().width * 1.5,
                                                       Continue.getLocalBounds().height + Continue.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {
                if(event_exit.key.code == Keyboard::Enter || Mouse::isButtonPressed(Mouse::Left))
                {
                    return 3;
                }
            }

            if (escape_selected == 1)
            {start_again.setFillColor(buttons_chosen); exit.setFillColor(buttons_color); Continue.setFillColor(buttons_color);}
            else if (escape_selected == 0)
            {start_again.setFillColor(buttons_color); exit.setFillColor(buttons_chosen); Continue.setFillColor(buttons_color);}
            else if (escape_selected == 2)
            {Continue.setFillColor(buttons_chosen); exit.setFillColor(buttons_color  ); start_again.setFillColor(buttons_color);}
        }
        window.draw(EscapeShape);
        window.draw(pause_text); window.draw(exit); window.draw(start_again); window.draw(Continue);
        window.display();
    }
}
#endif //SF_ESCAPE_H
