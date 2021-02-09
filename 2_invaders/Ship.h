#pragma once

#include <SFML/Graphics.hpp>
#include "bullet.h"

//extern std::vector<Bullet*> bullets;

class Ship : public sf::Sprite 
{
protected:
    sf::IntRect _sprite;

    Ship();
public:
    explicit Ship(sf::IntRect ir);
    //Deconstructor
    virtual ~Ship() = 0;
    //Update, can be overwritten because "virtual"
    virtual void Update(const float& dt);

};

class Invader : public Ship {
public:
    static bool direction;
    static float speed;

    Invader(sf::IntRect ir, sf::Vector2f pos);
    Invader();
    void Update(const float& dt) override;
};

class Player : public Ship {
public:
    Player(sf::IntRect ir, sf::Vector2f pos);
    Player();
    void Update(const float& dt) override;
};