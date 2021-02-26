#pragma once
#include "game.h"

class Entity
{
protected:
	sf::CircleShape _shape;
	sf::Vector2f pos;
	Entity(sf::CircleShape shp);
public:
	explicit Entity();
	virtual ~Entity() = 0;
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderWindow& window) const;

	const sf::Vector2f getPosition();

	void move(const sf::Vector2f& pos);
};