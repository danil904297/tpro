//
// Created by Администратор on 18.12.2023.
//

#ifndef SF_LOSE_H
#define SF_LOSE_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "external/nlohmann/json.hpp"
#include "fstream"
#include "iostream"
using json = nlohmann::json;



using  namespace sf;



int lose(RenderWindow& window)
{
    Color buttons_color = Color::Black, buttons_chosen = Color::Red;
    std::ifstream file("tekst.json");
    json data = json::parse(file);

    file.close();


    sf::Color i;

    std::string name_a = "g";
    std::string color_a = "";
    std::string Game_a = to_string(data["countRound"]);
    std::string time_a = to_string(data["timeOfRound"]);

    if(data["Color"] == 1) color_a = "White";
    if(data["Color"] == 2) color_a = "Blue";
    if(data["Color"] == 3) color_a = "Red";
    if(data["Color"] == 4) color_a = "Pink";

    int win_width = 1200, win_height = 1000;
    RectangleShape ExitShape;
    Texture Texture_window;
    Texture_window.loadFromFile("../menu/lose.jpg");
    ExitShape.setTexture(&Texture_window);
    ExitShape.setPosition(Vector2f(VideoMode::getDesktopMode().width/2 - win_width/2, VideoMode::getDesktopMode().height/2 - win_height/2));
    ExitShape.setSize(Vector2f(win_width, win_height));
    ExitShape.setPosition(Vector2f(VideoMode::getDesktopMode().width/2 - win_width/2, VideoMode::getDesktopMode().height/2 - win_height/2));

    Texture name;
    Texture color;
    Texture game_score;
    Texture time;

    name.loadFromFile("../menu/name.png");
    color.loadFromFile("../menu/color.png");
    game_score.loadFromFile("../menu/score.png");
    time.loadFromFile("../menu/time.png");

    Sprite Name, Color, Game_score, Time;
    Name.setTexture(name);
    Color.setTexture(color);
    Game_score.setTexture(game_score);
    Time.setTexture(time);
    Name.setPosition(win_width / 2 - win_width / 4, win_height / 3 - win_height / 20);
    Color.setPosition(win_width / 2 - win_width / 4, win_height / 3 + win_height / 12);
    Game_score.setPosition(win_width / 2 - win_width / 6.5, win_height / 3 + win_height / 5);
    Time.setPosition(win_width / 2 - win_width / 4, win_height / 3 + win_height / 3);



    Font font;
    if (!font.loadFromFile("../cmake-build-debug/arial.ttf")) exit(3);

    Text name_s(name_a, font, 75);
    name_s.setFillColor(Color::Black);
    name_s.setPosition(win_width / 2 + win_width / 2.7, win_height / 3 - win_height / 20);

    Text color_s(color_a, font, 75);
    color_s.setFillColor(Color::Black);
    color_s.setPosition(win_width / 2 + win_width / 2.7, win_height / 3 + win_height / 12);

    Text Gamescore(Game_a, font, 75);
    Gamescore.setFillColor(Color::Black);
    Gamescore.setPosition(win_width / 2 + win_width / 2.7, win_height / 3 + win_height / 5);

    Text time_s(time_a, font, 75);
    time_s.setFillColor(Color::Black);
    time_s.setPosition(win_width / 2 + win_width / 2.7, win_height / 3 + win_height / 3);


    Text exit_text("You lose", font, 75);
    exit_text.setFillColor(Color::Black);
    exit_text.setPosition(ExitShape.getPosition().x + (ExitShape.getLocalBounds().width - exit_text.getLocalBounds().width)/2, ExitShape.getPosition().y + 40);

    Text exit_yes("Exit", font, 65);
    exit_yes.setFillColor(buttons_color);
    exit_yes.setPosition(ExitShape.getPosition().x + 100,
                         ExitShape.getPosition().y + ExitShape.getLocalBounds().height - exit_yes.getLocalBounds().height - 100);


    Text exit_no("Start again", font, 65);
    exit_no.setFillColor(buttons_chosen);
    exit_no.setPosition(ExitShape.getPosition().x + ExitShape.getLocalBounds().width - 350,
                        ExitShape.getPosition().y + ExitShape.getLocalBounds().height - exit_no.getLocalBounds().height - 100);

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
                    return 2;
                }
            }

            if (exit_selected == 1)
            {exit_no.setFillColor(buttons_chosen); exit_yes.setFillColor(buttons_color);}
            else if (exit_selected == 0)
            {exit_no.setFillColor(buttons_color); exit_yes.setFillColor(buttons_chosen);}
        }
        window.draw(ExitShape);
        window.draw(exit_text);
        window.draw(exit_yes);
        window.draw(exit_no);
        window.draw(Name);
        window.draw(Color);
        window.draw(Game_score);
        window.draw(Time);
        window.draw(name_s);
        window.draw(color_s);
        window.draw(Gamescore);
        window.draw(time_s);

        window.display();
    }
    return 2;
}
#endif //SF_LOSE_H
