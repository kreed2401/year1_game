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

bool Ship::is_exploded(void)const 
{
	return _exploded;
}

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
	Invader::speed = Invader::speed + 2.5f;
	int invadersAlive = 0;
	for (int i = 0; i < ships.size(); ++i)
	{
		if (ships[i] != player && !ships[i]->is_exploded()) invadersAlive++;
	}
	if (invadersAlive <= 0)
	{

	}

}


Invader::Invader() : Ship() {}


Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) 
{
	setOrigin(16, 16);
	setPosition(pos);
	Invader::speed = 10;
}

void Invader::reset(sf::IntRect ir, sf::Vector2f pos)
{

}

//
//Invader Update
//
void Invader::Update(const float& dt) 
{
	Ship::Update(dt);

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);
	
	static float deathtime = 0.2f;
	static float firetime = 0.0f;
	firetime -= dt;
	

	//Randomly Fire Towards Player
	if (firetime <= 0 && rand() % 100 == 0 && !is_exploded()) 
	{
		Bullet::Fire(getPosition(), true);
		firetime = 4.0f + (rand()%60);
	}

	if ((direction && getPosition().x > gameWidth - 16) && !is_exploded() || (!direction && getPosition().x < 16)&& !is_exploded()) {
		direction = !direction;
		for (int i = 0; i < ships.size(); ++i) 
		{
			if(ships[i]!=player) ships[i]->move(0, 24);
		}
	}

	if (_exploded)
	{
		bool gone = false;
		deathtime -= dt;
		if (deathtime <= 0 && !gone) 
		{
			setTextureRect(IntRect(0, 0, 0, 0));
			gone = true;
			deathtime = 0.2f;
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

	static float firetime = 0.0f;
	firetime -= dt;
	static float deathtime = 1.0f;
	if (!_exploded) 
	{
		if (direction < 0)
		{
			if (getPosition().x > 16) move(direction * 200 * dt, 0);
		}

		if (direction > 0)
		{
			if (getPosition().x < gameWidth - 16)move(direction * 200 * dt, 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Space) && firetime <= 0)
		{
			float x = Player::getPosition().x - 16;
			float y = Player::getPosition().y - 32;
			Vector2f pos = Vector2f(x, y);
			Bullet::Fire(pos, false);
			firetime = 0.7f;
			canShoot = false;
		}

		if (!Keyboard::isKeyPressed(Keyboard::Space))canShoot = true;
	}
	
}