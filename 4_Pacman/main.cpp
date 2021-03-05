#include <SFML/Graphics.hpp>
#include <string>
#include "ecm.h"
#include "system_renderer.h"
#include "Player.h"
#include "Ghost.h"
#include "game.h"
#include "pacman.h"

using namespace sf;
using namespace std;


sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Pacman");

shared_ptr<Scene> gameScene;
shared_ptr<Scene> menuScene;
shared_ptr<Scene> activeScene;

void Load()
{
    Renderer::initialise(window);

    // Load Scene-Local Assets
    gameScene.reset(new GameScene());
    menuScene.reset(new MenuScene());
    gameScene->load();
    menuScene->load();
    // Start at main menu
    activeScene = menuScene;
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
    activeScene->update(dt);
    //em.update(dt);
}

void Render(sf::RenderWindow& window)
{
    activeScene->render();
    //em.render();
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