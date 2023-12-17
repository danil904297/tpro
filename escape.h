//
// Created by Администратор on 17.12.2023.
//

#ifndef SF_ESCAPE_H
#define SF_ESCAPE_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "ExitOne.h"



using  namespace sf;

void Escape(RenderWindow& window)
{

    Color buttons_color = Color::Black, buttons_chosen = Color::Red;

    int escape_width = 800, escape_height = 300;
    RectangleShape EscapeShape;
    EscapeShape.setPosition(Vector2f(VideoMode::getDesktopMode().width/2 - escape_width/2, VideoMode::getDesktopMode().height/2 - escape_height/2));
    EscapeShape.setSize(Vector2f(escape_width, escape_height));
    EscapeShape.setFillColor(Color(234, 203, 166));
    EscapeShape.setOutlineThickness(5);
    EscapeShape.setOutlineColor(Color(167, 147, 123));

    Font font;
    if (!font.loadFromFile("../cmake-build-debug/arial.ttf")) exit(3);

    Text pause_text("Pause", font, 75);
    pause_text.setFillColor(Color::Black);
    pause_text.setPosition(EscapeShape.getPosition().x + (EscapeShape.getLocalBounds().width - pause_text.getLocalBounds().width)/2, EscapeShape.getPosition().y + 40);

    Text exit("Exit", font, 65);
    exit.setFillColor(buttons_color);
    exit.setPosition(EscapeShape.getPosition().x + 100,
                     EscapeShape.getPosition().y + EscapeShape.getLocalBounds().height - exit.getLocalBounds().height - 60);

    Text start_again("Start again", font, 65);
    start_again.setFillColor(buttons_chosen);
    start_again.setPosition(EscapeShape.getPosition().x + EscapeShape.getLocalBounds().width - 200,
                            EscapeShape.getPosition().y + EscapeShape.getLocalBounds().height - start_again.getLocalBounds().height - 60);

    Text Continue("Continue", font, 65);
    Continue.setFillColor(buttons_color);
    Continue.setPosition(EscapeShape.getPosition().x + 100,
                     EscapeShape.getPosition().y + EscapeShape.getLocalBounds().height - Continue.getLocalBounds().height - 60);

    int escape_selected = 1;

    while (window.isOpen())
    {
        Event event_exit;
        while (window.pollEvent(event_exit))
        {
            if (event_exit.type == Event::KeyReleased)
            {
                if (event_exit.key.code == Keyboard::Escape) {
                    //menu(&window);
                }
                if(event_exit.type == Event::Closed) window.close();
            }

            if(IntRect(exit.getPosition().x, exit.getPosition().y, exit.getLocalBounds().width * 1.5,
                       exit.getLocalBounds().height + exit.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {escape_selected = 0;}

            else if(IntRect(start_again.getPosition().x, start_again.getPosition().y, start_again.getLocalBounds().width * 1.5,
                            start_again.getLocalBounds().height + start_again.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {escape_selected = 1;}
            else if(IntRect(Continue.getPosition().x, Continue.getPosition().y, Continue.getLocalBounds().width * 1.5,
                            Continue.getLocalBounds().height + Continue.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {escape_selected = 1;}

            else if (event_exit.type == Event::KeyPressed)
            {
                if(event_exit.key.code == Keyboard::Right) ++escape_selected %=2;
                if(event_exit.key.code == Keyboard::Left) {if(escape_selected==0) escape_selected = 1; else --escape_selected %=2;}
            }

            if (escape_selected == 0 && IntRect(exit.getPosition().x, exit.getPosition().y, exit.getLocalBounds().width * 1.5,
                                              exit.getLocalBounds().height + exit.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {
                if(event_exit.key.code == Keyboard::Enter || Mouse::isButtonPressed(Mouse::Left))
                {
                    if(ExitOne()== 1) window.close();
                    //RoundOutput("../../SystemFiles/Rounds.cfg", 0);
                }
            } else if (escape_selected == 1 && IntRect(start_again.getPosition().x, start_again.getPosition().y, start_again.getLocalBounds().width * 1.5,
                                                     start_again.getLocalBounds().height + start_again.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {
                if(event_exit.key.code == Keyboard::Enter || Mouse::isButtonPressed(Mouse::Left))
                {
                    sleep(milliseconds(100));

                    //menuOptions(window); return;
                }
            } else if (escape_selected == 1 && IntRect(Continue.getPosition().x, Continue.getPosition().y, Continue.getLocalBounds().width * 1.5,
                                                       Continue.getLocalBounds().height + Continue.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {
                if(event_exit.key.code == Keyboard::Enter || Mouse::isButtonPressed(Mouse::Left))
                {
                    sleep(milliseconds(100));

                    //menuOptions(window); return;
                }
            }


            if (escape_selected == 1)
            {start_again.setFillColor(buttons_chosen); exit.setFillColor(buttons_color);}
            else if (escape_selected == 0)
            {start_again.setFillColor(buttons_color); exit.setFillColor(buttons_chosen);}
//            else if (escape_selected == 1)
//            {Continue.setFillColor(buttons_color); exit.setFillColor(buttons_chosen);}
        }
        window.draw(EscapeShape);
        window.draw(pause_text); window.draw(exit); window.draw(start_again); window.draw(Continue);
        window.display();
    }
}
#endif //SF_ESCAPE_H
