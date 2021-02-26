#pragma once
#include "game.h"

class Entity : sf::Sprite
{
protected:
	sf::CircleShape _shape;
	sf::Vector2f pos;
	Entity(sf::CircleShape shp);
public:
	explicit Entity();
	virtual ~Entity() = 0;
	virtual void Update(const float& dt);
};