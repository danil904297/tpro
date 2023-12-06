#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

#ifndef MAP_H
#define MAP_H



class Map {
private:
	sf::Vector2i playerPos;
	std::vector<sf::Vector2i> enemyPos;
	void setUpInitialState();
	void setUpEnemyPositions();
	void setUpTiles();

public:
	std::vector <std::vector<Game*>> tiles;
	int gridLength;
	Map();
};

#endif // !MAP_H1