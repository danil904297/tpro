#include "SFML/Graphics.hpp"
#include "Menu.h"


using namespace sf;
int main()
{

    // Создание окна игры
    sf::RenderWindow window(sf::VideoMode(2160, 1600), "Трон");
    menu(window);

}