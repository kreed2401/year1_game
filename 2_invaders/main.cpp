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
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));

    Invader* inv = new Invader(sf::IntRect(0, 0, 32, 32), { 100,100 });
    ships.push_back(inv);
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

     Invader::speed = 20.0f;

     Load();
     while (window.isOpen())
     {
         window.clear();
         //Update(window);
         Render(window);
         window.display();
     }
     return 0;
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

