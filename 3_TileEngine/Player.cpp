#include "player.h"
using namespace sf;
using namespace std;

const Keyboard::Key controls[4] =
{
    Keyboard::W,//P Up
    Keyboard::S,//P Down
    Keyboard::A,//P Left
    Keyboard::D//P Right
};

void Player::Update(double dt) 
{
    if (Keyboard::isKeyPressed(controls[0])) 
    {
        move(Vector2f(0, -_speed * dt));
    }
    if (Keyboard::isKeyPressed(controls[1]))
    {
        move(Vector2f(0, _speed * dt));
    }

    if (Keyboard::isKeyPressed(controls[2]))
    {
        move(Vector2f(-_speed * dt, 0));
    }
    if (Keyboard::isKeyPressed(controls[3]))
    {
        move(Vector2f(_speed * dt, 0));
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