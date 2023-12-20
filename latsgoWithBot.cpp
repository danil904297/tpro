//
// Created by 1 on 18.12.2023.
//
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include <bitset>
#include <string>
#include "settings.h"
#include "player.h"
#include "win.h"
#include "global.h"
#include "nlohmann/json.hpp"
#include "fstream"
#include "iostream"
using json = nlohmann::json;

void latsgoWithBot(RenderWindow& window)
{
    //sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tron Game", sf::Style::Titlebar | sf::Style::Close); // Window declarations
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    sf::Font font; // Loading a font

    if (!font.loadFromFile("arial.ttf"))
    {
        printf("Error: Loading a font\n");
    }

    sf::Text text1, text2; // Declaring texts displaying scores
    text1.setFont(font);
    text2.setFont(font);

    int score1 = 0;
    int score2 = 0;
    int count = 0;
    int randomMove = 0;

    text1.setString("a");
    text2.setString(std::to_string(score2));

    text1.setCharacterSize(TEXT_SIZE);
    text2.setCharacterSize(TEXT_SIZE);

    srand(time(NULL)); // Setting random initial positions and directions

    int pos1x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos1y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
    int pos2x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos2y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));

    int dir1 = rand() % 4;
    int dir2 = rand() % 4;
    std::ifstream file("tekst.json");
    json data = json::parse(file);
    file.close();

    Player Player1(pos1x, pos1y, dir1, sf::Color::Blue);
    if (data["Color"] == 4) {
        std::cout << 1;
        Player Player1(pos1x, pos1y, dir1, sf::Color::White);
    }

    //Player Player1(pos1x, pos1y, dir1, sf::Color::Blue);
    Player Player2(pos2x, pos2y, dir2, sf::Color::Red);

    sf::VertexArray Wall;

    text1.setFillColor(Player1.getColor());
    text2.setFillColor(Player2.getColor());

    sf::FloatRect textBox1 = text1.getLocalBounds();
    sf::FloatRect textBox2 = text2.getLocalBounds();

    text1.setOrigin(textBox1.left + textBox1.width / 2, textBox1.top + textBox1.height / 2);
    text2.setOrigin(textBox2.left + textBox2.width / 2, textBox2.top + textBox2.height / 2);

    text1.setPosition(sf::Vector2f(WIDTH / 10, HEIGHT / 20));
    text2.setPosition(sf::Vector2f((WIDTH * 9) / 10, HEIGHT / 20));

    for (int j = 0; j <= 5; j++) // Creating boundaries on the screen
    {
        for (int i = 0; i < WIDTH; i++)
        {
            Wall.append(sf::Vertex(sf::Vector2f(i, j), Color(123, 17, 237)));
            Wall.append(sf::Vertex(sf::Vector2f(i, HEIGHT - 1 - j), Color(123, 17, 237)));

            Player1.setSingleWall(i, j);
            Player1.setSingleWall(i, HEIGHT - 1 - j);

            Player2.setSingleWall(i, j);
            Player2.setSingleWall(i, HEIGHT - 1 - j);
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

            Player2.setSingleWall(j, i);
            Player2.setSingleWall(WIDTH - 1 - j, i);
        }
    }

    Player1.changeDirection(dir1);
    Player2.changeDirection(dir2);


    while (window.isOpen()) // Game loop
    {
        ++count;
        sf::Event event;

        while (window.pollEvent(event)) // Event loop
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(score1 == 10 || score2 ==10) {
            if (win(window) == 1){ return;}
            else {score2 = 0; score1 = 0;}
        }
        window.clear(sf::Color::Black);
            if(count % 15 == 0) {
                randomMove = std::rand() % 4;
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Keyboard input
            Player1.changeDirection(up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            Player1.changeDirection(down);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            Player1.changeDirection(left);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            Player1.changeDirection(right);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            Escape(window);
            if (Escape(window) == 1) { return;}
            if (Escape(window)== 2) {
                score1= 0;
                score2 = 0;
            }
            if (Escape(window)== 3) {}
        }

        if (randomMove == 0)
            Player2.changeDirection(up);
        if (randomMove == 1)
            Player2.changeDirection(down);
        if (randomMove == 2)
            Player2.changeDirection(left);
        if (randomMove ==3)
            Player2.changeDirection(right);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        Vertex A = Player1.move();
        Vertex B = Player2.move();

        if (Player1.isCrashed(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y))
            score2++;
        if (Player2.isCrashed(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y))
            score1++;

        bool crashed = 0;

        if (Player1.isCrashed(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y) ||
            Player2.isCrashed(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y))
        {
            crashed = 1;
        }

        Wall.append(A);
        Player1.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player1.setWall(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y);
        Player1.update();

        Wall.append(B);
        Player2.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player2.setWall(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y);
        Player2.update();

        if (crashed)
        {
            Wall.clear();
            Player1.wallReset();
            Player2.wallReset();

            pos1x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos1y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
            pos2x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos2y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));

            dir1 = rand() % 4;
            dir2 = rand() % 4;

            Player1.setPosition(pos1x, pos1y);
            Player2.setPosition(pos2x, pos2y);

            Player1.changeDirection(dir1);
            Player2.changeDirection(dir2);

            for (int j = 0; j <= 5; j++) // Creating boundaries on the screen
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
        text2.setString(std::to_string(score2));

        window.draw(Player1.getShape()); // Drawing
        window.draw(Player2.getShape());

        window.draw(Wall);

        window.draw(text1);
        window.draw(text2);

        window.display();
    }

    return;
}

void latsgoWithTwoBot(RenderWindow& window)
{
    //sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tron Game", sf::Style::Titlebar | sf::Style::Close); // Window declarations
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    sf::Font font; // Loading a font

    if (!font.loadFromFile("arial.ttf"))
    {
        printf("Error: Loading a font\n");
    }

    sf::Text text1, text2; // Declaring texts displaying scores
    text1.setFont(font);
    text2.setFont(font);

    int score1 = 0;
    int score2 = 0;
    int count = 0;
    int randomMoveOne = 0;
    int randomMoveTwo = 0;

    text1.setString("a");
    text2.setString(std::to_string(score2));

    text1.setCharacterSize(TEXT_SIZE);
    text2.setCharacterSize(TEXT_SIZE);

    srand(time(NULL)); // Setting random initial positions and directions

    int pos1x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos1y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
    int pos2x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos2y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
    int pos3x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos3y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));

    int dir1 = rand() % 4;
    int dir2 = rand() % 4;
    int dir3 = rand() % 4;

    Player Player1(pos1x, pos1y, dir1, sf::Color::Blue);
    Player Player2(pos2x, pos2y, dir2, sf::Color::Red);
    Player Player3(pos3x, pos3y, dir3, sf::Color::Red);

    sf::VertexArray Wall;

    text1.setFillColor(Player1.getColor());
    text2.setFillColor(Player2.getColor());

    sf::FloatRect textBox1 = text1.getLocalBounds();
    sf::FloatRect textBox2 = text2.getLocalBounds();

    text1.setOrigin(textBox1.left + textBox1.width / 2, textBox1.top + textBox1.height / 2);
    text2.setOrigin(textBox2.left + textBox2.width / 2, textBox2.top + textBox2.height / 2);

    text1.setPosition(sf::Vector2f(WIDTH / 10, HEIGHT / 20));
    text2.setPosition(sf::Vector2f((WIDTH * 9) / 10, HEIGHT / 20));

    for (int j = 0; j <= 5; j++) // Creating boundaries on the screen
    {
        for (int i = 0; i < WIDTH; i++)
        {
            Wall.append(sf::Vertex(sf::Vector2f(i, j), Color(123, 17, 237)));
            Wall.append(sf::Vertex(sf::Vector2f(i, HEIGHT - 1 - j), Color(123, 17, 237)));

            Player1.setSingleWall(i, j);
            Player1.setSingleWall(i, HEIGHT - 1 - j);

            Player2.setSingleWall(i, j);
            Player2.setSingleWall(i, HEIGHT - 1 - j);

            Player3.setSingleWall(i, j);
            Player3.setSingleWall(i, HEIGHT - 1 - j);
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

            Player2.setSingleWall(j, i);
            Player2.setSingleWall(WIDTH - 1 - j, i);

            Player3.setSingleWall(j, i);
            Player3.setSingleWall(WIDTH - 1 - j, i);
        }
    }

    Player1.changeDirection(dir1);
    Player2.changeDirection(dir2);
    Player3.changeDirection(dir3);


    while (window.isOpen()) // Game loop
    {
        ++count;
        sf::Event event;

        while (window.pollEvent(event)) // Event loop
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(score1 == 10 || score2 ==10)
        {
            win(window);
        }

        window.clear(sf::Color::Black);
        if(count % 15 == 0) {
            randomMoveOne = std::rand() % 4;
            randomMoveTwo = std::rand() % 4;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Keyboard input
            Player1.changeDirection(up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            Player1.changeDirection(down);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            Player1.changeDirection(left);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            Player1.changeDirection(right);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            Escape(window);
            if (Escape(window) == 1) { return;}
            if (Escape(window)== 2) {
                score1= 0;
                score2 = 0;
            }
            if (Escape(window)== 3) {}
        }

        if (randomMoveOne == 0)
            Player2.changeDirection(up);
        if (randomMoveOne == 1)
            Player2.changeDirection(down);
        if (randomMoveOne == 2)
            Player2.changeDirection(left);
        if (randomMoveOne ==3)
            Player2.changeDirection(right);

        if (randomMoveTwo == 0)
            Player3.changeDirection(up);
        if (randomMoveTwo == 1)
            Player3.changeDirection(down);
        if (randomMoveTwo == 2)
            Player3.changeDirection(left);
        if (randomMoveTwo ==3)
            Player3.changeDirection(right);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        Vertex A = Player1.move();
        Vertex B = Player2.move();
        Vertex C = Player3.move();

        if (Player1.isCrashed(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y))
            score2++;
        if (Player2.isCrashed(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y))
            score1++;
        if (Player3.isCrashed(C.position.x, C.position.y, Player3.getPosition().x, Player3.getPosition().y))
            score1++;

        bool crashed = 0;

        if (Player1.isCrashed(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y) ||
            Player2.isCrashed(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y) ||
            Player3.isCrashed(C.position.x, C.position.y, Player3.getPosition().x, Player3.getPosition().y))
        {
            crashed = 1;
        }

        Wall.append(A);
        Player1.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player1.setWall(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y);
        Player1.update();

        Wall.append(B);
        Player2.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player2.update();

        Wall.append(C);
        Player3.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player3.update();

        if (crashed)
        {
            Wall.clear();
            Player1.wallReset();
            Player2.wallReset();

            pos1x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos1y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
            pos2x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos2y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
            pos3x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos3y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));

            dir1 = rand() % 4;
            dir2 = rand() % 4;
            dir2 = rand() % 4;

            Player1.setPosition(pos1x, pos1y);
            Player2.setPosition(pos2x, pos2y);
            Player3.setPosition(pos3x, pos3y);

            Player1.changeDirection(dir1);
            Player2.changeDirection(dir2);
            Player3.changeDirection(dir3);

            for (int j = 0; j <= 5; j++) // Creating boundaries on the screen
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
        text2.setString(std::to_string(score2));

        window.draw(Player1.getShape()); // Drawing
        window.draw(Player2.getShape());
        window.draw(Player3.getShape());

        window.draw(Wall);

        window.draw(text1);
        window.draw(text2);

        window.display();
    }

    return;
}

void latsgoWithThreeBot(RenderWindow& window)
{
    //sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tron Game", sf::Style::Titlebar | sf::Style::Close); // Window declarations
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    sf::Font font; // Loading a font

    if (!font.loadFromFile("arial.ttf"))
    {
        printf("Error: Loading a font\n");
    }

    sf::Text text1, text2; // Declaring texts displaying scores
    text1.setFont(font);
    text2.setFont(font);

    int score1 = 0;
    int score2 = 0;
    int count = 0;
    int randomMoveOne = 0;
    int randomMoveTwo = 0;
    int randomMoveThree = 0;

    text1.setString("a");
    text2.setString(std::to_string(score2));

    text1.setCharacterSize(TEXT_SIZE);
    text2.setCharacterSize(TEXT_SIZE);

    srand(time(NULL)); // Setting random initial positions and directions

    int pos1x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos1y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
    int pos2x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos2y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
    int pos3x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos3y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
    int pos4x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
    int pos4y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));

    int dir1 = rand() % 4;
    int dir2 = rand() % 4;
    int dir3 = rand() % 4;
    int dir4 = rand() % 4;

    Player Player1(pos1x, pos1y, dir1, sf::Color::Blue);
    Player Player2(pos2x, pos2y, dir2, sf::Color::Red);
    Player Player3(pos3x, pos3y, dir3, sf::Color::Red);
    Player Player4(pos4x, pos4y, dir4, sf::Color::Red);

    sf::VertexArray Wall;

    text1.setFillColor(Player1.getColor());
    text2.setFillColor(Player2.getColor());

    sf::FloatRect textBox1 = text1.getLocalBounds();
    sf::FloatRect textBox2 = text2.getLocalBounds();

    text1.setOrigin(textBox1.left + textBox1.width / 2, textBox1.top + textBox1.height / 2);
    text2.setOrigin(textBox2.left + textBox2.width / 2, textBox2.top + textBox2.height / 2);

    text1.setPosition(sf::Vector2f(WIDTH / 10, HEIGHT / 20));
    text2.setPosition(sf::Vector2f((WIDTH * 9) / 10, HEIGHT / 20));

    for (int j = 0; j <= 5; j++) // Creating boundaries on the screen
    {
        for (int i = 0; i < WIDTH; i++)
        {
            Wall.append(sf::Vertex(sf::Vector2f(i, j), Color(123, 17, 237)));
            Wall.append(sf::Vertex(sf::Vector2f(i, HEIGHT - 1 - j), Color(123, 17, 237)));

            Player1.setSingleWall(i, j);
            Player1.setSingleWall(i, HEIGHT - 1 - j);

            Player2.setSingleWall(i, j);
            Player2.setSingleWall(i, HEIGHT - 1 - j);

            Player3.setSingleWall(i, j);
            Player3.setSingleWall(i, HEIGHT - 1 - j);

            Player4.setSingleWall(i, j);
            Player4.setSingleWall(i, HEIGHT - 1 - j);
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

            Player2.setSingleWall(j, i);
            Player2.setSingleWall(WIDTH - 1 - j, i);

            Player3.setSingleWall(i, j);
            Player3.setSingleWall(i, HEIGHT - 1 - j);

            Player4.setSingleWall(i, j);
            Player4.setSingleWall(i, HEIGHT - 1 - j);
        }
    }

    Player1.changeDirection(dir1);
    Player2.changeDirection(dir2);
    Player3.changeDirection(dir3);
    Player4.changeDirection(dir4);


    while (window.isOpen()) // Game loop
    {
        ++count;
        sf::Event event;

        while (window.pollEvent(event)) // Event loop
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(score1 == 10 || score2 ==10)
        {
            win(window);
        }

        window.clear(sf::Color::Black);
        if(count % 15 == 0) {
            randomMoveOne = std::rand() % 4;
            randomMoveTwo = std::rand() % 4;
            randomMoveThree = std::rand() % 4;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Keyboard input
            Player1.changeDirection(up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            Player1.changeDirection(down);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            Player1.changeDirection(left);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            Player1.changeDirection(right);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            Escape(window);
            if (Escape(window) == 1) { return;}
            if (Escape(window)== 2) {
                score1= 0;
                score2 = 0;
            }
            if (Escape(window)== 3) {}
        }

        if (randomMoveOne == 0)
            Player2.changeDirection(up);
        if (randomMoveOne == 1)
            Player2.changeDirection(down);
        if (randomMoveOne == 2)
            Player2.changeDirection(left);
        if (randomMoveOne ==3)
            Player2.changeDirection(right);

        if (randomMoveTwo == 0)
            Player3.changeDirection(up);
        if (randomMoveTwo == 1)
            Player3.changeDirection(down);
        if (randomMoveTwo == 2)
            Player3.changeDirection(left);
        if (randomMoveTwo ==3)
            Player3.changeDirection(right);

        if (randomMoveThree == 0)
            Player4.changeDirection(up);
        if (randomMoveThree == 1)
            Player4.changeDirection(down);
        if (randomMoveThree == 2)
            Player4.changeDirection(left);
        if (randomMoveThree ==3)
            Player4.changeDirection(right);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        Vertex A = Player1.move();
        Vertex B = Player2.move();
        Vertex C = Player3.move();
        Vertex D = Player4.move();

        if (Player1.isCrashed(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y))
            score2++;
        if (Player2.isCrashed(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y))
            score1++;
        if (Player3.isCrashed(C.position.x, C.position.y, Player3.getPosition().x, Player3.getPosition().y))
            score1++;
        if (Player4.isCrashed(D.position.x, D.position.y, Player4.getPosition().x, Player4.getPosition().y))
            score1++;

        bool crashed = 0;

        if (Player1.isCrashed(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y) ||
            Player2.isCrashed(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y) ||
            Player3.isCrashed(C.position.x, C.position.y, Player3.getPosition().x, Player3.getPosition().y) ||
            Player4.isCrashed(D.position.x, D.position.y, Player4.getPosition().x, Player4.getPosition().y))
        {
            score1++;
            crashed = 1;
        }

        Wall.append(A);
        Player1.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player1.setWall(B.position.x, B.position.y, Player2.getPosition().x, Player2.getPosition().y);
        Player1.setWall(C.position.x, C.position.y, Player3.getPosition().x, Player3.getPosition().y);
        Player1.setWall(D.position.x, D.position.y, Player4.getPosition().x, Player4.getPosition().y);
        Player1.update();

        Wall.append(B);
        Player2.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player2.update();

        Wall.append(C);
        Player3.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player3.update();

        Wall.append(D);
        Player4.setWall(A.position.x, A.position.y, Player1.getPosition().x, Player1.getPosition().y);
        Player4.update();

        if (crashed)
        {
            Wall.clear();
            Player1.wallReset();
            Player2.wallReset();

            pos1x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos1y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
            pos2x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos2y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
            pos3x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos3y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));
            pos4x = (WIDTH / 4) + rand() % (WIDTH - (WIDTH / 2));
            pos4y = (HEIGHT / 4) + rand() % (HEIGHT - (HEIGHT / 2));

            dir1 = rand() % 4;
            dir2 = rand() % 4;
            dir3 = rand() % 4;
            dir4 = rand() % 4;

            Player1.setPosition(pos1x, pos1y);
            Player2.setPosition(pos2x, pos2y);
            Player3.setPosition(pos3x, pos3y);
            Player4.setPosition(pos4x, pos4y);

            Player1.changeDirection(dir1);
            Player2.changeDirection(dir2);
            Player3.changeDirection(dir3);
            Player4.changeDirection(dir4);

            for (int j = 0; j <= 5; j++) // Creating boundaries on the screen
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
        text2.setString(std::to_string(score2));

        window.draw(Player1.getShape()); // Drawing
        window.draw(Player2.getShape());
        window.draw(Player3.getShape());
        window.draw(Player4.getShape());

        window.draw(Wall);

        window.draw(text1);
        window.draw(text2);

        window.display();
    }

    return;
}