#include "cmp_actor_movement.h"
#include <LevelSystem.h>

using namespace sf;

void ActorMovementComponent::update(double dt) {}

ActorMovementComponent::ActorMovementComponent(Entity* p) : _speed(100.0f), Component(p) {}

bool ActorMovementComponent::validMove(const Vector2f& pos)
{
	std::cout << pos.x;
	std::cout << ",";
	std::cout << pos.y;
	std::cout << "\n";
	return (LevelSystem::getTileAt(pos) != LevelSystem::WALL);
	//return true;
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

const Keyboard::Key controls[4] =
{
	Keyboard::W,//P Up
	Keyboard::S,//P Down
	Keyboard::A,//P Left
	Keyboard::D//P Right
};

PlayerMovementComponent::PlayerMovementComponent(Entity* p) : ActorMovementComponent(p) {};

Vector2f direction;

void PlayerMovementComponent::update(double dt)
{

	if (Keyboard::isKeyPressed(controls[0])) direction = (Vector2f(0, -_speed * dt));
	if (Keyboard::isKeyPressed(controls[1])) direction = (Vector2f(0, _speed * dt));
	if (Keyboard::isKeyPressed(controls[2])) direction = (Vector2f(-_speed * dt, 0));
	if (Keyboard::isKeyPressed(controls[3])) direction = (Vector2f(_speed * dt, 0));

	move(direction);
}

//################################ACTOR#############################################
/*
EnemyAIComponent::EnemyAIComponent(Entity* p) : ActorMovementComponent(p) {};

void EnemyAIComponent::update(double dt)
{


}
*/

