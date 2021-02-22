#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"
#include "game.h"
using namespace sf;
using namespace std;

Player player;

void Load() 
{
    

}

void Update(RenderWindow& window)
{
    static Clock clock;
    float dt = clock.restart().asSeconds();

    player.Update(dt);
}


void Render(RenderWindow& window)
{
    player.Render(window);
}

int main() 
{
        sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Maze");
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

