#include "game.h"

using namespace sf;
using namespace std;

Player* player;
vector<Entity*> entities;

void load()
{
    player = new Player(Vector2f(gameWidth / 2, gameHeight / 2),sf::Color::Yellow);
    entities.push_back(player);
    for (int i = 0; i != 4; i++) 
    {
        Ghost* ghost = new Ghost(Vector2f(gameWidth / 3 + (i * 50), gameHeight / 3), sf::Color::Red);
        entities.push_back(ghost);
    }
}

void Update(RenderWindow& window)
{
    static Clock clock;
    float dt = clock.restart().asSeconds();
}

void Render(RenderWindow& window)
{
    for(auto& e : entities)
    {
        e->Render(window);
    }
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