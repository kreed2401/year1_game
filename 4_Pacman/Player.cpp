#include "game.h"

using namespace sf;
using namespace std;

Player::Player() {};

Player::Player(sf::Vector2f pos, sf::Color col)
{
	
	CircleShape shape;
	shape.setFillColor(col);
	shape.setRadius(5.f);
	shape.setOrigin(5.f, 5.f);
	_shape = shape;
	_shape.setPosition(pos);
}

void Player::Update(const float& dt) 
{

}

void Player::Render(sf::RenderWindow& window) const
{
	window.draw(_shape);
}