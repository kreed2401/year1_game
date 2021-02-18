#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "ship.h"
#include "game.h"
#include "bullet.h"

using namespace sf;
using namespace std;
/*
const int gameWidth = 800;
const int gameHeight = 600;
*/
float direction = 0.0f;

sf::Texture spritesheet;
sf::Sprite invader;


//Location to Reference of Ships
std::vector<Ship*> ships;

Ship* player;

//Initilize Keyboard Controls
const Keyboard::Key controls[3] =
{
    Keyboard::A,//Left
    Keyboard::D,//Right
    Keyboard::Space,//Shoot
};



void Load() 
{
    

    if (!spritesheet.loadFromFile("res/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }

    Invader::speed = 30.0f;
    Invader::direction = true;


    player = new Player(IntRect(160,32,32,32),Vector2f(gameWidth/2,gameHeight-32));
    ships.push_back(player);

    for (int r = 0; r < invaders_rows; ++r) 
    {
        auto rect = IntRect(32*r, 0, 32, 32);
        for (int c = 0; c < invaders_columns; ++c) 
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

    if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

    direction = 0;

    if (Keyboard::isKeyPressed(controls[0]))
    {
            direction--;
    }

    if (Keyboard::isKeyPressed(controls[1]))
    {
        direction++;
    }
    Bullet::Update(dt);

    if (player->is_exploded()) 
    {
        static float deathtime = 2.0f;
        deathtime -= dt;
        if (deathtime <= 0) window.close();
    }

    if (Invader::shipsAlive <= 0) 
    {
        for (auto& s : ships) 
        {
            if (s!= player) 
            {
                s->reset();
            }
        }
    }
}

void Render(RenderWindow& window) 
{
    for (const auto s : ships)
    {
        window.draw(*s);
    }
    Bullet::Render(window);
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
