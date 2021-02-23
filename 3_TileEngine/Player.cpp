#include "player.h"
#include "LevelSystem.h"
#include "game.h"

using namespace sf;
using namespace std;


const Keyboard::Key controls[4] =
{
    Keyboard::W,//P Up
    Keyboard::S,//P Down
    Keyboard::A,//P Left
    Keyboard::D//P Right
};

bool validmove(Vector2f pos) 
{
    return (ls::getTileAt(pos) != ls::WALL);
}

void Player::Update(double dt) 
{
    if (Keyboard::isKeyPressed(controls[0])) 
    {
        if(validmove(Vector2f(getPosition().x,getPosition().y-5))) move(Vector2f(0, -_speed * dt));
    }
    if (Keyboard::isKeyPressed(controls[1]))
    {
        if (validmove(Vector2f(getPosition().x, getPosition().y+5))) move(Vector2f(0, _speed * dt));
    }

    if (Keyboard::isKeyPressed(controls[2]))
    {
        if (validmove(Vector2f(getPosition().x-5, getPosition().y)))move(Vector2f(-_speed * dt, 0));
    }
    if (Keyboard::isKeyPressed(controls[3]))
    {
        if (validmove(Vector2f(getPosition().x+5, getPosition().y)))move(Vector2f(_speed * dt, 0));
    }
 
    if(ls::getTileAt(getPosition()) == ls::END)
    {
        
        ls::loadLevelFile("res/levels/maze_2.txt");

        for (size_t y = 0; y < ls::getHeight(); ++y)
        {
            for (size_t x = 0; x < ls::getWidth(); ++x)
            {
                if (ls::getTile({ x,y }) == 1)setPosition(ls::getTilePosition({ x,y }));
            }
        }
        level++;
    }
    

    Entity::Update(dt);
}

Player::Player()
    : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) 
{
    _shape->setFillColor(Color::Magenta);
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Render(sf::RenderWindow& window) const 
{
    window.draw(*_shape);
}