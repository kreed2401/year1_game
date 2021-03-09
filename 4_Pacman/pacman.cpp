#include "pacman.h"
#include "game.h"
#include "ecm.h"
#include "cmp_sprite.h"


using namespace std;
using namespace sf;

sf::Font font;
sf::Text text;


void Scene::render() { _ents.render(); }
void Scene::update(double dt) { _ents.update(dt); }

void MenuScene::update(double dt) 
{
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


#define GHOSTS_COUNT 4

void GameScene::load() 
{
    /*
    shared_ptr<Player>player(new Player());
    em.list.push_back(player);
    
    shared_ptr<Ghost>ghost(new Ghost());
    auto s = ghost->addComponent<ShapeComponent>();
    s->setShape<sf::CircleShape>(12.f);
    em.list.push_back(ghost);
    */


    auto player = make_shared<Entity>();
    auto s = player->addComponent<ShapeComponent>();
    s->setShape<sf::CircleShape>(12.f);
    s->getShape().setFillColor(Color::Yellow);
    s->getShape().setOrigin(Vector2f(21.f, 12.f));
    
    _ents.list.push_back(player);

    const sf::Color ghost_cols[]{ { 208,62,25 }, { 213,133,28 }, { 70,191,238 }, { 234,130,229 } };

    for(int i = 0; i < GHOSTS_COUNT; ++i)
    {
        auto ghost = make_shared<Entity>();
        auto s = ghost->addComponent<ShapeComponent>();
        s->setShape<sf::CircleShape>(12.f);
        s->getShape().setFillColor(ghost_cols[i % 4]);
        s->getShape().setOrigin(Vector2f(12.f, 12.f));

        _ents.list.push_back(ghost);
    }

    for(auto s : _ents.list)
    {
        cout << " ###THERE IS AN ENTITY### ";
    }

    player->setPosition(Vector2f(gameWidth / 2, gameHeight / 2));
    cout << (player->getPosition());
}

void GameScene::update(double dt)
{
    _ents.update(dt);
    if (Keyboard::isKeyPressed(Keyboard::Tab)) 
    {
        activeScene = menuScene;
    }
    Scene::update(dt);
    
}

void GameScene::render()
{
    _ents.render();
}