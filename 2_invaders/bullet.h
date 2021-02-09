#pragma once
#include <SFML/Graphics.hpp>


class Bullet : public sf::Sprite {
public:
	static void Update(const float& dt);
	Bullet(const sf::Vector2f& pos, const bool mode);
	static void Render(sf::RenderWindow& window);
	static void Fire(const sf::Vector2f& pos, const bool mode);
	~Bullet() = default;

protected:
	Bullet();
	sf::IntRect _sprite;
	//false=player bullet, true=Enemy bullet
	bool _mode = true;
	static unsigned char bulletPointer;
	static Bullet bullets[256];

	void _Update(const float& dt);

};