#include "ship.h"
#include "game.h"
#include "bullet.h"
#include <iostream>

using namespace sf;
using namespace std;

Bullet::Bullet() {}

Bullet::Bullet(const Vector2f& pos, bool mode) : Sprite()
{
	setPosition(pos);
	_mode = mode;
	if (mode)
	{
		_sprite= IntRect(64, 32, 16, 16);
	}
	else 
	{
		_sprite = IntRect(32, 32, 16, 16);
	}
	
	setTexture(spritesheet);
	setTextureRect(_sprite);
}
void Bullet::Update(const float& dt) 
{

}