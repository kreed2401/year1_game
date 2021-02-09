#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "ship.h"

using namespace sf;
using namespace std;

const int gameWidth = 800;
const int gameHeight = 600;

sf::Texture spritesheet;
sf::Sprite invader;

//Location to Reference of Ships
std::vector<Ship*> ships;



void Load() 
{
    if (!spritesheet.loadFromFile("res/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }

    Invader::speed = 30.0f;
    Invader::direction = true;

    //Invader* inv = new Invader(sf::IntRect(0, 0, 32, 32), { 100,100 });
    //ships.push_back(inv);

    int invader_rows = 6;
    int invader_columns = 12;

    for (int r = 0; r < invader_rows; ++r) 
    {
        auto rect = IntRect(32*r, 0, 32, 32);
        for (int c = 0; c < invader_columns; ++c) 
        {
            Vector2f position = Vector2f((gameWidth/4) + (32*c), 100 + (32*r));
            auto inv = new Invader(rect, position);
            ships.push_back(inv);
        }
    }
}

void Update(RenderWindow& window)
{
    static Clock clock;
    float dt = clock.restart().asSeconds();

    for (auto& s : ships)
    {
        s->Update(dt);
    };
}

void Render(RenderWindow& window) 
{
    for (const auto s : ships)
    {
        window.draw(*s);
    }
}



int main()
{
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Invaders");
    Load();
    while (window.isOpen())
    {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}
