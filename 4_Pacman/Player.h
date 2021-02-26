#pragma once
#include "Entity.h"

class Player : public Entity 
{
public:
	Player(sf::Vector2f pos);
	Player();
	void Update(const float& dt) override;
	void Render(RenderWindow& window);
};