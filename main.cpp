#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "fstream"
#include "nlohmann/json.hpp"
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
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Трон");
    menu(window);



}