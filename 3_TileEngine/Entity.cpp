#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace sf;
using namespace std;

const Vector2f Entity::getPosition() { return _position; }

void Entity::setPosition(const Vector2f &pos) { _position = pos; }

void Entity::move(const Vector2f& pos) { _position = pos; }

Entity::Entity() {};

Entity::Entity(unique_ptr<Shape> shp)
{
	
}

