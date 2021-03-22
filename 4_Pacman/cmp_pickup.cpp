#include "cmp_pickup.h"
#include "scene.h"
#include "ecm.h"
#include "pacman.h"
#include "cmp_actor_movement.h"


PickupComponent::PickupComponent(Entity* p) : Component(p) {};


void PickupComponent::update(double dt)
{
	/*
	for(auto e : activeScene->getEnts())
	{

			if (sqrt(pow(e->getPosition().y - _parent->getPosition().y, 2) + pow(e->getPosition().x - -_parent->getPosition().x, 2)))
			{
				auto cmp = e->GetCompatibleComponent<ActorMovementComponent>();
				if ()
				{
					std::cout << "DELETING" << std::endl;
					activeScene->updateScore(10.f);
					_parent->setForDelete();
					break;
				}

			}
		
	}*/
	if((sqrt(pow(_parent->getPosition().y - activeScene->getPlayer()->getPosition().y, 2) + pow(_parent->getPosition().x - activeScene->getPlayer()->getPosition().x, 2)) < 15.0f))
	{
		std::cout << "DELETING" << std::endl;
		activeScene->updateScore(10.f);
		_parent->setForDelete();
	}
}