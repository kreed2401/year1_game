#include "pacman.h"
#include "game.h"
#include "ecm.h"
#include "cmp_sprite.h"
#include "cmp_actor_movement.h"
#include "LevelSystem.h"
#include "cmp_enemy_ai.h"
#include "cmp_pickup.h"

using namespace std;
using namespace sf;

sf::Font font;
sf::Text text;


void Scene::render() { _ents.render(); }
void Scene::update(double dt) { _ents.update(dt); }
std::vector<std::shared_ptr<Entity>>& Scene::getEnts() { return _ents.list; }

vector<shared_ptr<Entity>> nibbles;

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

    auto plyr = make_shared<Entity>();
    auto s = plyr->addComponent<ShapeComponent>();
    s->setShape<sf::CircleShape>(12.f);
    s->getShape().setFillColor(Color::Yellow);
    s->getShape().setOrigin(Vector2f(12.f, 12.f));
    plyr->addComponent<PlayerMovementComponent>();
    player = plyr;
    _ents.list.push_back(player);

    const sf::Color ghost_cols[]{ { 208,62,25 }, { 213,133,28 }, { 70,191,238 }, { 234,130,229 } };

    ls::loadLevelFile("res/levels/pacman.txt", 25.0f);

    vector<sf::Vector2ul> enemySpawns = ls::findTiles(ls::TILE::ENEMY);

    for(int i = 0; i < GHOSTS_COUNT; ++i)
    {
        auto ghost = make_shared<Entity>();
        auto s = ghost->addComponent<ShapeComponent>();
        s->setShape<sf::CircleShape>(12.f);
        s->getShape().setFillColor(ghost_cols[i % 4]);
        s->getShape().setOrigin(Vector2f(12.f, 12.f));
        ghost->addComponent<EnemyAIComponent>();
        ghosts.push_back(ghost);
        _ents.list.push_back(ghost);

    }

    int ghostNo = 1;

    
    respawn();
}

shared_ptr<Entity> makeNibble(const Vector2ul& nl, bool big)
{
    auto cherry = make_shared<Entity>();
    auto s = cherry->addComponent<ShapeComponent>();
    s->setShape < sf::CircleShape>(6.0f);
    s->getShape().setFillColor(Color::Red);
    cherry->addComponent<PickupComponent>(big);
    cherry->setPosition(ls::getTilePosition(nl) + Vector2f(10.f, 10.f));
    return cherry;
}

void GameScene::respawn() 
{
    player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
    player->GetCompatibleComponent<ActorMovementComponent>()[0]->setSpeed(150.f);
    auto ghost_spawns = ls::findTiles(ls::ENEMY);
    for (auto& g : ghosts) {
        g->setPosition(
            ls::getTilePosition(ghost_spawns[rand() % ghost_spawns.size()]));
        g->GetCompatibleComponent<ActorMovementComponent>()[0]->setSpeed(100.0f);
    }
    
    for (auto n : nibbles)
    {
        n->setForDelete();
        n->reset();
    }
}
void GameScene::update(double dt)
{
    _ents.update(dt);
    if (Keyboard::isKeyPressed(Keyboard::Tab)) 
    {
        activeScene = menuScene;
    }
    Scene::update(dt);

    for(auto& g : ghosts)
    { 
        
        cout << length(g->getPosition() - player->getPosition()) << endl;
        if(sqrt(pow(g->getPosition().y - player->getPosition().y, 2) + pow(g->getPosition().x - player->getPosition().x, 2)) < 30.0f)
        {
            respawn();
        }
    }
}


void GameScene::render()
{
    ls::Render(Renderer::getWindow());
    _ents.render();
}