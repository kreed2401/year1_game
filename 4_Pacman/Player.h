#pragma once
#include "Entity.h"

class Player : public Entity 
{
public:
	
	Player();
	Player(sf::Vector2f pos, sf::Color col);
	void Update(const float& dt) override;
	void Render(sf::RenderWindow& window) const;
};