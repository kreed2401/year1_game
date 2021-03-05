#include "ecm.h"


using namespace std;
using namespace sf;

Entity::Entity() {};

Entity::~Entity() {}

void Entity::render() {}

void Entity::update(double dt) {}

void Entity::EntityManager::render() {}

void Entity::EntityManager::update(double dt) {}

const Vector2f& Entity::getPosition() const { return _position; }

Component::Component(Entity* const p) : _parent(p) {}

Component::~Component() {}