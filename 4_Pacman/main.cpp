#include "game.h"

using namespace sf;
using namespace std;

Player* player;

void load()
{
    player = new Player();
}

void Update(RenderWindow& window)
{
    static Clock clock;
    float dt = clock.restart().asSeconds();
}

void Render(RenderWindow& window)
{
    
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "PacMan");
    load();
    while (window.isOpen())
    {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}