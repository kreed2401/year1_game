#include "ship.h"
#include "game.h"
#include <iostream>
#include "bullet.h"
using namespace sf;
using namespace std;

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite() 
{
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};


void Ship::Update(const float& dt) {}

//Ship deconstructor. 
Ship::~Ship() = default;

//
//Code For Invaders
//

bool Invader::direction;
float Invader::speed;

void Ship::Explode() 
{
	setTextureRect(IntRect(128, 32, 32, 32));
	_exploded = true;
}


Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
}

//
//Invader Update
//
void Invader::Update(const float& dt) 
{
	Ship::Update(dt);

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);
	

	if ((direction && getPosition().x > gameWidth - 16) || (!direction && getPosition().x < 16)) {
		direction = !direction;
		for (int i = 0; i < ships.size(); ++i) 
		{
			if(ships[i]!=player) ships[i]->move(0, 24);
		}
	}
}

//
//Player Code
//

Player::Player() : Ship() {}

Player::Player(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) 
{
	setOrigin(16, 16);
	setPosition(pos);
}

bool canShoot = true;

void Player::Update(const float &dt)
{
	Ship::Update(dt);

	//static vector<Bullet*>bullets;

	if (direction < 0) 
	{
		if (getPosition().x > 16) move(direction * 200 * dt, 0);
	}

	if (direction > 0) 
	{
		if(getPosition().x < gameWidth - 16)move(direction * 200 * dt, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && canShoot)
	{
		
		canShoot = false;
	}

	if (!Keyboard::isKeyPressed(Keyboard::Space))canShoot = true;

}