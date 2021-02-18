#pragma once

#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite 
{
protected:
    sf::IntRect _sprite;
    bool _exploded = false;
    sf::Vector2f spawn;
    sf::IntRect texRec;

    Ship();
public:
    bool is_exploded() const;
    virtual void Explode();

    explicit Ship(sf::IntRect ir);
    //Deconstructor
    virtual ~Ship() = 0;
    //Update, can be overwritten because "virtual"
    virtual void Update(const float& dt);
    void reset();

};

class Invader : public Ship {
public:
    static bool direction;
    static float speed;
    static int shipsAlive;

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