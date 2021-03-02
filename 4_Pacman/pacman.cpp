#include "pacman.h"
#include "game.h"

using namespace std;
using namespace sf;

sf::Font font;
sf::Text text;


void Scene::render() { _ents.render(); }
void Scene::update(double dt) { _ents.update(dt); }

void MenuScene::update(double dt) {
	Scene::update(dt);

	

    if (Keyboard::isKeyPressed(Keyboard::Space)) 
    {
        activeScene = gameScene;
    }
}

void MenuScene::render() 
{
	Renderer::queue(&text);
	Scene::render();
}

void MenuScene::load() 
{
    font.loadFromFile("res/RobotoMono-VariableFont_wght.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    //Center the text "somewhat"
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(gameWidth / 3.0f, 0));

    text.setString("    Almost Pacman\n\n-PRESS SPACE TO START-");
}


Entity::EntityManager em;

void GameScene::load() 
{
    shared_ptr<Player>player(new Player());
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

void GameScene::update(double dt)
{
    em.update(dt);
    if (Keyboard::isKeyPressed(Keyboard::Tab)) 
    {
        activeScene = menuScene;
    }
    Scene::update(dt);
}

void GameScene::render()
{
    em.render();
}