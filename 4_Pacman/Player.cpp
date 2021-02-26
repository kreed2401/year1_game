#include "game.h"

using namespace sf;
using namespace std;

//Player::Player() : Entity() {}

Player::Player()
{
	CircleShape shape;
	shape.setFillColor(Color::Yellow);
	shape.setRadius(5.f);
	shape.setOrigin(5.f, 5.f);
	_shape = shape;
}

void Player::Update(const float& dt) 
{

}

void Player::Render(RenderWindow window)
{
	window.draw(_shape);
}