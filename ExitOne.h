//
// Created by Администратор on 18.12.2023.
//

#ifndef SF_EXITONE_H
#define SF_EXITONE_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
using namespace sf;

int ExitOne(RenderWindow& window)
{

    //sf::RenderWindow Exit(sf::VideoMode(1920, 1080), "Трон");
    Color buttons_color = Color::Black, buttons_chosen = Color::Red;

    int exit_width = 800, exit_height = 300;
    RectangleShape ExitShape;
    Texture Texture_window;
    Texture_window.loadFromFile("../menu/exit.jpg");
    ExitShape.setTexture(&Texture_window);
    ExitShape.setPosition(Vector2f(VideoMode::getDesktopMode().width/2 - exit_width/2, VideoMode::getDesktopMode().height/2 - exit_height/2));
    ExitShape.setSize(Vector2f(exit_width, exit_height));
    ExitShape.setPosition(Vector2f(VideoMode::getDesktopMode().width/2 - exit_width/2, VideoMode::getDesktopMode().height/2 - exit_height/2));

    Font font;
    if (!font.loadFromFile("../cmake-build-debug/arial.ttf")) exit(3);

    Text exit_text("Do you want exit?", font, 75);
    exit_text.setFillColor(Color::White     );
    exit_text.setPosition(ExitShape.getPosition().x + (ExitShape.getLocalBounds().width - exit_text.getLocalBounds().width)/2, ExitShape.getPosition().y + 40);

    Text exit_yes("Yes", font, 65);
    exit_yes.setFillColor(Color::White);
    exit_yes.setPosition(ExitShape.getPosition().x + 100,
                         ExitShape.getPosition().y + ExitShape.getLocalBounds().height - exit_yes.getLocalBounds().height - 60);

    Text exit_no("No", font, 65);
    exit_no.setFillColor(Color::White);
    exit_no.setPosition(ExitShape.getPosition().x + ExitShape.getLocalBounds().width - 200,
                        ExitShape.getPosition().y + ExitShape.getLocalBounds().height - exit_no.getLocalBounds().height - 60);

    int exit_selected = 1;

    while (window.isOpen())
    {
        Event event_exit;
        while (window.pollEvent(event_exit))
        {
            if (event_exit.type == Event::KeyReleased)
            {
                if (event_exit.key.code == Keyboard::Escape) {
                    return 1;
                }
                if(event_exit.type == Event::Closed) window.close();
            }

            if(IntRect(exit_yes.getPosition().x, exit_yes.getPosition().y, exit_yes.getLocalBounds().width * 1.5,
                       exit_yes.getLocalBounds().height + exit_yes.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {exit_selected = 0;}

            else if(IntRect(exit_no.getPosition().x, exit_no.getPosition().y, exit_no.getLocalBounds().width * 1.5,
                            exit_no.getLocalBounds().height + exit_no.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {exit_selected = 1;}

            else if (event_exit.type == Event::KeyPressed)
            {
                if(event_exit.key.code == Keyboard::Right) ++exit_selected %=2;
                if(event_exit.key.code == Keyboard::Left) {if(exit_selected==0) exit_selected = 1; else --exit_selected %=2;}
            }

            if (exit_selected == 0 && IntRect(exit_yes.getPosition().x, exit_yes.getPosition().y, exit_yes.getLocalBounds().width * 1.5,
                                              exit_yes.getLocalBounds().height + exit_yes.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {
                if(event_exit.key.code == Keyboard::Enter || Mouse::isButtonPressed(Mouse::Left))
                {
                    return 1;
                }
            } else if (exit_selected == 1 && IntRect(exit_no.getPosition().x, exit_no.getPosition().y, exit_no.getLocalBounds().width * 1.5,
                                                     exit_no.getLocalBounds().height + exit_no.getCharacterSize()/3).contains(Mouse::getPosition(window)))
            {
                if(event_exit.key.code == Keyboard::Enter || Mouse::isButtonPressed(Mouse::Left))
                {
                    return 3;
                }
            }

            if (exit_selected == 1)
            {exit_no.setFillColor(buttons_chosen); exit_yes.setFillColor(Color::White);}
            else if (exit_selected == 0)
            {exit_no.setFillColor(Color::White); exit_yes.setFillColor(buttons_chosen);}
        }
        window.draw(ExitShape);
        window.draw(exit_text); window.draw(exit_yes); window.draw(exit_no);
        window.display();
    }
    return 3;
}
#endif //SF_EXITONE_H
