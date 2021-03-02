#include "Player.h"
#include "system_renderer.h"
#include "game.h"
using namespace sf;
using namespace std;

const Keyboard::Key controls[4] =
{
	Keyboard::W,    //Up
	Keyboard::S,    //Down
	Keyboard::A,   //Left
	Keyboard::D,  //Right
};

void Player::Update(double dt) 
{
	//Move in four directions based on keys
	if (Keyboard::isKeyPressed(Keyboard::A)) 
	{
		move(Vector2f(-_speed * dt, 0));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) 
	{
		move(Vector2f(_speed * dt, 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) 
	{
		move(Vector2f(0, _speed * dt));
	}
	else if (Keyboard::isKeyPressed(Keyboard::W)) 
	{
		move(Vector2f(0, -_speed * dt));
	}
	Entity::Update(dt);
}

Player::Player() :_speed(200.0f), Entity(make_unique<CircleShape>(10.0f)) 
{
	_shape->setFillColor(Color::Yellow);
	_shape->setOrigin(Vector2f(25.0f, 25.0f));
	_shape->setPosition(Vector2f(gameWidth / 2, gameHeight / 2));
}

void Player::Render() const 
{
	//window.draw(*_shape);
	Renderer::queue(_shape.get());
}