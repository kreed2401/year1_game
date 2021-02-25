#include "ghost.h"
#include "game.h"

using namespace sf;
using namespace std;


void Ghost::Update(double dt)
{
    Entity::Update(dt);
}

Ghost::Ghost()
        : _speed(200.0f), Entity(make_unique<CircleShape>(10.f))
{
    _shape->setFillColor(Color::Red);
    _shape->setOrigin(Vector2f(10.f, 10.f));
}

void Ghost::Render(sf::RenderWindow& window) const
{
    window.draw(*_shape);
}