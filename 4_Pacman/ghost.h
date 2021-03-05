#pragma once
#include "ecm.h"

class Ghost :public Entity {
private:
	float _speed;

public:
	void update(double dt) override;
	Ghost();
	void render() override;
};