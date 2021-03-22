#include "cmp_pickup.h"
#include "scene.h"
#include "ecm.h"
#include "pacman.h"
#include "cmp_actor_movement.h"


PickupComponent::PickupComponent(Entity* p) : Component(p) {};


void PickupComponent::update(double dt)
{
	for(auto e : activeScene->getEnts())
	{
			if (sqrt(pow(e->getPosition().y - _parent->getPosition().y, 2) + pow(e->getPosition().x - -_parent->getPosition().x, 2)))
			{
				auto cmp = e->GetCompatibleComponent<ActorMovementComponent>();
				if (cmp.empty())
				{
					activeScene->updateScore(10.f);
					_parent->setForDelete();
					break;
				}

			}
	}
}