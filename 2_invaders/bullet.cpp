//bullet.cpp
#include "bullet.h"
#include "game.h"
#include "Ship.h"
using namespace sf;
using namespace std;

Bullet::Bullet (const sf::Vector2f& pos, const bool mode) : Sprite()
{
	IntRect texRect;
	_mode = mode;
	if (mode) 
	{
		texRect = IntRect(64, 32, 32, 32);
	}
	else 
	{
		texRect = IntRect(32, 32, 32, 32);
	}
	setPosition(pos);
	setTexture(spritesheet);
	setTextureRect(texRect);
};

void Bullet::Fire(const sf::Vector2f& pos, const bool mode) 
{
    bullets[++bulletPointer].Bullet::Bullet(pos, mode);
}


void Bullet::Update(const float& dt) 
{
    for (auto b : bullets) 
    {
        b._Update(dt);
    }
}

void Bullet::Render(RenderWindow& window) 
{
    for (const auto b : bullets)
    {
        window.draw(b);
    }
}

void Bullet::_Update(const float& dt) 
{
    if (getPosition().y < -32 || getPosition().y > gameHeight + 32) 
    {
        return;
    }
    else 
    {
        move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
        const FloatRect boundingBox = getGlobalBounds();

        for (auto s : ships) 
        {
            if (!_mode && s == player) 
            {
                continue;
            }
            if (_mode && s != player)
            {
                continue;
            }
            //if (!s->is_exploded() &&
            //    s->getGlobalBounds().intersects(boundingBox)) 
            //{
            //    s->Explode();
            //    setPosition(-100, -100);
            //    return;
            //}
        }
    }
};