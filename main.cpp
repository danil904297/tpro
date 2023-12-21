#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "external/nlohmann/json.hpp"
#include "fstream"
#include "iostream"

using json = nlohmann::json;

using namespace sf;
int main()
{
    std::ofstream file("tekst.json");
    json data;

    data["Color"] = 1;
    data["qwe"] = 1;
    data["bot"] = 1;
    std::cout << data;
    file << data;

    file.close();
    // Создание окна игры
    sf::RenderWindow window(sf::VideoMode(2520, 1680), "Трон");
    menu(window);



}