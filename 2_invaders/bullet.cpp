#include "bullet.h"
#include "game.h"
#include "Ship.h"
#include <iostream>
using namespace sf;
using namespace std;

IntRect texRect;
unsigned char Bullet::bulletPointer;
Bullet Bullet::bullets[256];

Bullet::Bullet() { };

Bullet::Bullet (const sf::Vector2f& pos, const bool mode) : Sprite()
{
    setTexture(spritesheet);
    _mode = mode;
};

void Bullet::Fire(const sf::Vector2f& pos, const bool mode) 
{
    bullets[bulletPointer].setTexture(spritesheet);
    cerr << ("Pew");
    bullets[bulletPointer]._mode = mode;
    if (mode)
    {
        texRect = IntRect(64, 32, 32, 32);
    }
    else
    {
        texRect = IntRect(32, 32, 32, 32);
    }
    
    bullets[bulletPointer].setPosition(pos);
    int x = bullets[bulletPointer].getPosition().x;
    bullets[bulletPointer].setTextureRect(texRect);

    cerr << (to_string(x));
    bulletPointer++;
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
        cerr << ("above screen");
        return;
    }
    else 
    {
        move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
        const FloatRect boundingBox = getGlobalBounds();
        /*for (auto s : ships) 
        {
            if (!_mode && s == player) 
            {
                continue;
            }
            if (_mode && s != player)
            {
                continue;
            }
            if (!s->is_exploded() &&
                s->getGlobalBounds().intersects(boundingBox)) 
            {
                s->Explode();
                setPosition(-100, -100);
                return;
            }
        }*/
    }

    
};