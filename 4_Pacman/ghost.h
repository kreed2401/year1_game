#pragma once
#include "Entity.h"

class Ghost : public Entity
{
public:
	Ghost();
	Ghost(sf::Vector2f pos, sf::Color col);
	void Update(const float& dt) override;
	void Render(sf::RenderWindow& window) const;
};