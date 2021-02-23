#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"
#include "game.h"
#include "LevelSystem.h"


using namespace sf;
using namespace std;

Player player;
int level;
void Load() 
{
    level = 1;

    ls::loadLevelFile("res/levels/maze.txt");

    for (size_t y = 0; y < ls::getHeight(); ++y) 
    {
        for (size_t x = 0; x < ls::getWidth(); ++x) 
        {
            cout << ls::getTile({ x, y });
            if (ls::getTile({ x,y }) == 1)player.setPosition(ls::getTilePosition({ x,y }));
        }
        cout << endl;
    }
}

float timeTaken = 0;

void Update(RenderWindow& window)
{
    static Clock clock;
    float dt = clock.restart().asSeconds();

    
    timeTaken += dt;

    player.Update(dt);

    if (level == 3) 
    {
        cout << "\nTime Taken ";
        cout << timeTaken;
        cout << " Seconds\n";
        window.close();
    }
}


void Render(RenderWindow& window)
{
    ls::Render(window);
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

