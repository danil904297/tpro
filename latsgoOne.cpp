#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include <bitset>
#include <string>
#include "settings.h"
#include "external/nlohmann/json.hpp"
#include "player.h"
#include "escape.h"
#include "win.h"
#include "iostream"
#include "fstream"
#include "time.h"

void latsgo1(RenderWindow& window)
{
    Clock clock;
    //sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tron Game", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    sf::Font font;

    if (!font.loadFromFile("../cmake-build-debug/arial.ttf"))
    {
        printf("Error: Loading a font\n");
    }

    sf::Text text1, text2, text3, text4, text5; // Declaring texts displaying scores
    text1.setFont(font);
    text2.setFont(font);
    text3.setFont(font);
    text4.setFont(font);
    text5.setFont(font);

    int score1 = 0;
    int gameTime = 0;
    int timeArr[50];
    int curRound = 0;
    int resTime = 0;
    int count = 0;
    int randomMove = 0;
    std::string name1 = "bleb";
    std::string color1 = "l";
    sf::Color i;

    std::ifstream file("tekst.json");
    json data = json::parse(file);
    file.close();
    std::cout << data["Color"];
    if(data["Color"] == 1) {
        i = sf::Color::White;
        color1 = "White";
    }
    if(data["Color"] == 2) {
        i = sf::Color::Blue;
        color1 = "Blue";
    }
    if(data["Color"] == 3) {
        i = sf::Color::Red;
        color1 = "Red";
    }
    if(data["Color"] == 4) {
        i = sf::Color::Magenta;
        color1 = "Magenta";
    }
    text1.setString("a");
    text2.setString(std::to_string(gameTime));
    text3.setString(name1);
    text4.setString(color1);


    text1.setCharacterSize(TEXT_SIZE);
    text2.setCharacterSize(TEXT_SIZE);
    text3.setCharacterSize(TEXT_SIZE);
    text4.setCharacterSize(TEXT_SIZE);

    srand(time(NULL));

    int pos1x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos1y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));

    int dir1 = rand() % 4;


    Player Player1(pos1x, pos1y, dir1, i);

    sf::VertexArray Wall;

    text1.setFillColor(Player1.getColor());
    text2.setFillColor(sf::Color::White);
    text3.setFillColor(Player1.getColor());
    text4.setFillColor(Player1.getColor());

    sf::FloatRect textBox1 = text1.getLocalBounds();
    sf::FloatRect textBox2 = text2.getLocalBounds();
    sf::FloatRect textBox3 = text3.getLocalBounds();
    sf::FloatRect textBox4 = text4.getLocalBounds();

    text1.setOrigin(textBox1.left + textBox1.width / 2, textBox1.top + textBox1.height / 2);
    text2.setOrigin(textBox2.left + textBox2.width / 2, textBox2.top + textBox2.height / 2);
    text3.setOrigin(textBox3.left + textBox3.width / 2, textBox3.top + textBox3.height / 2);
    text4.setOrigin(textBox4.left + textBox4.width / 2, textBox4.top + textBox4.height / 2);


    text1.setPosition(sf::Vector2f(WIDTH / 10, HEIGHT / 20));
    text2.setPosition(sf::Vector2f((WIDTH * 5) / 10, HEIGHT / 20));
    text3.setPosition(sf::Vector2f((WIDTH * 3) / 10, HEIGHT / 20));
    text4.setPosition(sf::Vector2f((WIDTH * 2.8) / 10, HEIGHT / 10));

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
        ++count;
        gameTime = clock.getElapsedTime().asSeconds();
        sf::Event event;
        if(score1 == 10 ) {
            for(int i = 0; i < 20; ++i) {
                resTime += timeArr[i];
            }
            std::ifstream file("tekst.json");
            json data = json::parse(file);
            file.close();
            data["countRound"] = curRound;
            data["timeOfRound"] = resTime;
            std::ofstream file_close("tekst.json");
            file_close << data;
            file_close.close();

            if (win(window) == 1){ return;}
            else {score1 = 0;}
        }
        while (window.pollEvent(event)) // Event loop
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        if(data["qwe"] == 1) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Keyboard input
                Player1.changeDirection(up);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                Player1.changeDirection(down);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                Player1.changeDirection(left);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                Player1.changeDirection(right);
        }
        else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                Player1.changeDirection(up);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                Player1.changeDirection(down);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                Player1.changeDirection(left);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                Player1.changeDirection(right);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            Escape(window);
            if (Escape(window) == 1) { return;}
            if (Escape(window)== 2) {
                score1= 0;

            }
            if (Escape(window)== 3) {}
        }


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
            timeArr[curRound] = gameTime;
            Wall.clear();
            Player1.wallReset();
            clock.restart();
            curRound++;

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
        text2.setString(std::to_string(gameTime));
        text3.setString(name1);
        text4.setString(color1);


        window.draw(Player1.getShape());

        window.draw(Wall);

        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);

        window.display();
    }

    return;
}