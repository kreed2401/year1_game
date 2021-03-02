#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"
#include "system_renderer.h"
#include "Player.h"
#include "Ghost.h"
#include "game.h"


using namespace sf;
using namespace std;


sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Pacman");

Entity::EntityManager em;

//Ghost ghost;


void Load()
{
    Renderer::initialise(window);
    shared_ptr<Player>player(new Player()) ;
    em.list.push_back(player);
    shared_ptr<Ghost>ghost1(new Ghost(sf::Color::Red, -30));
    shared_ptr<Ghost>ghost2(new Ghost(sf::Color::Blue, -10));
    shared_ptr<Ghost>ghost3(new Ghost(sf::Color::Magenta, 10));
    shared_ptr<Ghost>ghost4(new Ghost(sf::Color::Cyan, 30));
    em.list.push_back(ghost1);
    em.list.push_back(ghost2);
    em.list.push_back(ghost3);
    em.list.push_back(ghost4);
}


void Update(RenderWindow& window)
{
    static Clock clock;
    float dt = clock.restart().asSeconds();
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
            return;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
    }

    em.update(dt);
}

void Render(sf::RenderWindow& window)
{

    em.render(window);
    Renderer::render();
}



int main() {

    window.setVerticalSyncEnabled(true);

    Load();

    while (window.isOpen()) {
        window.clear();

        Update(window);
        Render(window);

        window.display();
    }
    return 0;
}