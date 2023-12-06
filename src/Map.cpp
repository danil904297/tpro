#include "pch.h"
#include "Map.h"

Map::Map() {
	gridLength = 8;
	setUpInitialState();
}

void Map::setUpInitialState() {
	playerPos = sf::Vector2i(gridLength - 1, gridLength - 1);
	setUpEnemyPositions();
	setUpTiles();

}

void Map::setUpEnemyPositions() {
	enemyPos.clear();
	enemyPos.push_back(sf::Vector2i(0, 2));
	enemyPos.push_back(sf::Vector2i(6, 0));
	enemyPos.push_back(sf::Vector2i(2, 7));
}

void Map::setUpTiles() {
	tiles.clear();
	std::vector<Game*>	firstRow;
	firstRow.push_back(new Game("sprite/fon.png", 0, 0, true));
	firstRow.push_back(new Game("sprite/fon.png", 50, 0, false));
	firstRow.push_back(new Game("sprite/fon.png", 100, 0, true));
	firstRow.push_back(new Game("sprite/fon.png", 150, 0, false));
	firstRow.push_back(new Game("sprite/fon.png", 200, 0, true));
	firstRow.push_back(new Game("sprite/fon.png", 250, 0, true));
	firstRow.push_back(new Game("sprite/fon.png", 300, 0, true));
	firstRow.push_back(new Game("sprite/fon.png", 350, 0, true));
	tiles.push_back(firstRow);

	std::vector<Game*>	secondRow;
	secondRow.push_back(new Game("sprite/fon.png", 0, 0, true));
	secondRow.push_back(new Game("sprite/fon.png", 50, 0, true));
	secondRow.push_back(new Game("sprite/fon.png", 100, 0, true));
	secondRow.push_back(new Game("sprite/fon.png", 150, 0, false));
	secondRow.push_back(new Game("sprite/fon.png", 200, 0, true));
	secondRow.push_back(new Game("sprite/fon.png", 250, 0, true));
	secondRow.push_back(new Game("sprite/fon.png", 300, 0, true));
	secondRow.push_back(new Game("sprite/fon.png", 350, 0, true));
	tiles.push_back(secondRow);

	std::vector<Game*>	thirdRow;
	thirdRow.push_back(new Game("sprite/fon.png", 0, 0, true));
	thirdRow.push_back(new Game("sprite/fon.png", 50, 0, true));
	thirdRow.push_back(new Game("sprite/fon.png", 100, 0, true));
	thirdRow.push_back(new Game("sprite/fon.png", 150, 0, true));
	thirdRow.push_back(new Game("sprite/fon.png", 200, 0, true));
	thirdRow.push_back(new Game("sprite/fon.png", 250, 0, true));
	thirdRow.push_back(new Game("sprite/fon.png", 300, 0, true));
	thirdRow.push_back(new Game("sprite/fon.png", 350, 0, true));
	tiles.push_back(thirdRow);

	std::vector<Game*>	fourthRow;
	fourthRow.push_back(new Game("sprite/fon.png", 0, 0, true));
	fourthRow.push_back(new Game("sprite/fon.png", 50, 0, true));
	fourthRow.push_back(new Game("sprite/fon.png", 100, 0, true));
	fourthRow.push_back(new Game("sprite/fon.png", 150, 0, true));
	fourthRow.push_back(new Game("sprite/fon.png", 200, 0, true));
	fourthRow.push_back(new Game("sprite/fon.png", 250, 0, true));
	fourthRow.push_back(new Game("sprite/fon.png", 300, 0, true));
	fourthRow.push_back(new Game("sprite/fon.png", 350, 0, true));
	tiles.push_back(fourthRow);

	std::vector<Game*>	fifthRow;
	fifthRow.push_back(new Game("sprite/fon.png", 0, 0, true));
	fifthRow.push_back(new Game("sprite/fon.png", 50, 0, true));
	fifthRow.push_back(new Game("sprite/fon.png", 100, 0, true));
	fifthRow.push_back(new Game("sprite/fon.png", 150, 0, false));
	fifthRow.push_back(new Game("sprite/fon.png", 200, 0, true));
	fifthRow.push_back(new Game("sprite/fon.png", 250, 0, true));
	fifthRow.push_back(new Game("sprite/fon.png", 300, 0, true));
	fifthRow.push_back(new Game("sprite/fon.png", 350, 0, true));
	tiles.push_back(fifthRow);

	std::vector<Game*>	sixthRow;
	sixthRow.push_back(new Game("sprite/fon.png", 0, 0, true));
	sixthRow.push_back(new Game("sprite/fon.png", 50, 0, false));
	sixthRow.push_back(new Game("sprite/fon.png", 100, 0, true));
	sixthRow.push_back(new Game("sprite/fon.png", 150, 0, false));
	sixthRow.push_back(new Game("sprite/fon.png", 200, 0, true));
	sixthRow.push_back(new Game("sprite/fon.png", 250, 0, true));
	sixthRow.push_back(new Game("sprite/fon.png", 300, 0, true));
	sixthRow.push_back(new Game("sprite/fon.png", 350, 0, true));
	tiles.push_back(sixthRow);

	std::vector<Game*>	seventhRow;
	seventhRow.push_back(new Game("sprite/fon.png", 0, 0, true));
	seventhRow.push_back(new Game("sprite/fon.png", 50, 0, false));
	seventhRow.push_back(new Game("sprite/fon.png", 100, 0, true));
	seventhRow.push_back(new Game("sprite/fon.png", 150, 0, false));
	seventhRow.push_back(new Game("sprite/fon.png", 200, 0, true));
	seventhRow.push_back(new Game("sprite/fon.png", 250, 0, true));
	seventhRow.push_back(new Game("sprite/fon.png", 300, 0, true));
	seventhRow.push_back(new Game("sprite/fon.png", 350, 0, true));
	tiles.push_back(seventhRow);

	std::vector<Game*>	eighthRow;
	eighthRow.push_back(new Game("sprite/fon.png", 0, 0, true));
	eighthRow.push_back(new Game("sprite/fon.png", 50, 0, false));
	eighthRow.push_back(new Game("sprite/fon.png", 100, 0, true));
	eighthRow.push_back(new Game("sprite/fon.png", 150, 0, false));
	eighthRow.push_back(new Game("sprite/fon.png", 200, 0, true));
	eighthRow.push_back(new Game("sprite/fon.png", 250, 0, true));
	eighthRow.push_back(new Game("sprite/fon.png", 300, 0, true));
	eighthRow.push_back(new Game("sprite/fon.png", 350, 0, true));
	tiles.push_back(eighthRow);

}