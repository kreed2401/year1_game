#include "cmp_actor_movement.h"
#include <LevelSystem.h>

using namespace sf;

void ActorMovementComponent::update(double dt) {}

ActorMovementComponent::ActorMovementComponent(Entity* p) : _speed(100.0f), Component(p) {}

bool ActorMovementComponent::validMove(const Vector2f& pos)
{
	//return (LevelSystem::getTileAt(pos) != LevelSystem::WALL);
	return false;
}

void ActorMovementComponent::move(const Vector2f& p)
{
	auto pp = _parent->getPosition() + p;
	if(validMove(pp))
	{
		_parent->setPosition(pp);
	}
}

void ActorMovementComponent::move(float x, float y)
{
	move(Vector2f(x, y));
}

float ActorMovementComponent::getSpeed() const { return _speed; }
void ActorMovementComponent::setSpeed(float speed) { _speed = speed; }


//#################################PLAYER###########################################

PlayerMovementComponent::PlayerMovementComponent(Entity* p) : ActorMovementComponent(p) {};

void PlayerMovementComponent::update(double dt)
{
	
}

//################################ACTOR#############################################

EnemyAIComponent::EnemyAIComponent(Entity* p) : ActorMovementComponent(p) {};

void EnemyAIComponent::update(double dt)
{

}

