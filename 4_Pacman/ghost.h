#pragma once
#include "Entity.h"

class Ghost : public Entity
{
public:
	Ghost(sf::Vector2f pos);
	Ghost();
	void Update(const float& dt) override;
};