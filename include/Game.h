#include <SFML/Graphics.hpp>

#ifndef GAME_H

#define GAME_H

class Game{
public:
	bool isPassable;
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;
	Game(std::string, float, float, bool);
	bool setUpSprite(std::string);
};

#endif // !GAME_H
