#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:
	static void Update(const float &dt);
	static void Render(sf::RenderWindow& window);
	static void Fire(const sf::Vector2f& pos, const bool mode);

	Bullet(const sf::Vector2f& pos, const bool mode);
	~Bullet() = default;

protected:

	static unsigned char bulletPointer;
	static Bullet bullets[256];
	//Called by the static update
	void _Update(const float &dt);

	Bullet();
	//false=player bullet, true=Enemy bullet
	bool _mode;
};