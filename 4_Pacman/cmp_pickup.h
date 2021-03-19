#pragma once
#include "pacman.h"

class PickupComponent : public Component
{

public:
	explicit PickupComponent(Entity* p);
	PickupComponent() = delete;
	void render() override {}
	void update(double dt) override;
};
