#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include <bitset>
#include <string>
#include "settings.h"
#include "player.h"

int latsgo1()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tron Game", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    sf::Font font;

    if (!font.loadFromFile("arial.ttf"))
    {
        printf("Error: Loading a font\n");
    }

    sf::Text text1;
    text1.setFont(font);

    int score1 = 0;

    text1.setString("a");

    text1.setCharacterSize(TEXT_SIZE);

    srand(time(NULL));

    int pos1x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos1y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));

    int dir1 = rand() % 4;


    Player Player1(pos1x, pos1y, dir1, sf::Color::Red);

    sf::VertexArray Wall;

    text1.setFillColor(Player1.getColor());

    sf::FloatRect textBox1 = text1.getLocalBounds();

    text1.setOrigin(textBox1.left + textBox1.width / 2, textBox1.top + textBox1.height / 2);

    text1.setPosition(sf::Vector2f(WIDTH / 10, HEIGHT / 20));

    for (int j = 0; j <= 5; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            Wall.append(sf::Vertex(sf::Vector2f(i, j), Color(123, 17, 237)));
            Wall.append(sf::Vertex(sf::Vector2f(i, HEIGHT - 1 - j), Color(123, 17, 237)));

            Player1.setSingleWall(i, j);
            Player1.setSingleWall(i, HEIGHT - 1 - j);
        }
    }

    for (int j = 0; j <= 5; j++)
    {
        for (int i = 0; i < HEIGHT; i++)
        {
            Wall.append(sf::Vertex(sf::Vector2f(j, i), Color(123, 17, 237)));
            Wall.append(sf::Vertex(sf::Vector2f(WIDTH - 1 - j, i), Color(123, 17, 237)));

            Player1.setSingleWall(j, i);
            Player1.setSingleWall(WIDTH - 1 - j, i);
        }
    }

    Player1.changeDirection(dir1);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            Player1.changeDirection(up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            Player1.changeDirection(down);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            Player1.changeDirection(left);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            Player1.changeDirection(right);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();


        Vertex A = Player1.move();

        if (Player1.isCrashed(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y))
            score1++;

        bool crashed = 0;

        if (Player1.isCrashed(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y))
        {
            crashed = 1;
        }

        Wall.append(A);
        Player1.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player1.update();


        if (crashed)
        {
            Wall.clear();
            Player1.wallReset();

            pos1x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos1y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));

            dir1 = rand() % 4;

            Player1.setPosition(pos1x, pos1y);

            Player1.changeDirection(dir1);

            for (int j = 0; j <= 5; j++)
            {
                for (int i = 0; i < WIDTH; i++)
                {
                    Wall.append(sf::Vertex(sf::Vector2f(i, j), Color(123, 17, 237)));
                    Wall.append(sf::Vertex(sf::Vector2f(i, HEIGHT - 1 - j), Color(123, 17, 237)));
                }
            }

            for (int j = 0; j <= 5; j++)
            {
                for (int i = 0; i < HEIGHT; i++)
                {
                    Wall.append(sf::Vertex(sf::Vector2f(j, i), Color(123, 17, 237)));
                    Wall.append(sf::Vertex(sf::Vector2f(WIDTH - 1 - j, i), Color(123, 17, 237)));
                }
            }
        }

        text1.setString(std::to_string(score1));

        window.draw(Player1.getShape());

        window.draw(Wall);

        window.draw(text1);

        window.display();
    }

    return 0;
}