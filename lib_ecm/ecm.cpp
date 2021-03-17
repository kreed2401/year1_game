#include "ecm.h"


using namespace std;
using namespace sf;

Entity::Entity() : _position({ 0, 0 }), _rotation(0), _alive(true), _visible(true), _fordeletion(false) {};

Entity::~Entity() {}

void Entity::render() 
{
	for(auto c : _components)
	{
		c->render();
	}
}

void Entity::update(double dt) 
{
	for(auto c : _components)
	{
		c->update(dt);
	}
}

void EntityManager::render() 
{
	//cout << "EM RENDER";

	for(auto e : list)
	{
		e->render();
		
	}

}

void EntityManager::update(double dt) 
{
	for(auto e : list)
	{
		e->update(dt);
	}
}

void Entity::setPosition(const Vector2f& pos) 
{ 
	cout << pos.x << endl;
	cout << pos.y << endl;
	_position = pos; 
}

const Vector2f& Entity::getPosition() const { return _position; }

Component::Component(Entity* const p) : _parent(p) {}

Component::~Component() {}