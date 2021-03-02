#include "Ghost.h"
#include "game.h"
using namespace sf;
using namespace std;

void Ghost::Update(double dt) {

	Entity::Update(dt);
}

Ghost::Ghost(sf::Color col, int pos) :_speed(200.0f), Entity(make_unique<CircleShape>(10.0f)) {
	_shape->setFillColor(col);
	_shape->setOrigin(Vector2f(5.0f, 5.0f));
	_shape->setPosition(Vector2f(gameWidth / 2 + pos, gameHeight / 3));
}

void Ghost::Render(sf::RenderWindow& window) const 
{
	window.draw(*_shape);
}