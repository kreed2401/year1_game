#include "Entity.h"
#include "Player.h"
#include "ghost.h"
#include "game.h"

using namespace sf;
using namespace std;

Player player;
Ghost blinky;
Ghost pinky;
Ghost inky;
Ghost clyde;
vector<Entity*> entities;

void load()
{
    
    player.setPosition(Vector2f(gameWidth / 2, gameHeight -200));
    blinky.setPosition(Vector2f(gameWidth / 2, gameHeight / 3));
}

void Update(RenderWindow& window)
{
    static Clock clock;
    float dt = clock.restart().asSeconds();
    player.Update(dt);
    blinky.Update(dt);
}

void Render(RenderWindow& window)
{
    player.Render(window);
    blinky.Render(window);
    pinky.Render(window);
    inky.Render(window);
    clyde.Render(window);
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