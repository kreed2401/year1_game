#pragma once
#include "Entity.h"

class Ghost :public Entity {
private:
	float _speed;

public:
	void Update(double dt) override;
	Ghost(sf::Color col, int pos);
	void Render() const override;
};