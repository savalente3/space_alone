#ifndef Enemy_hpp
#define Enemy_hpp

#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class Enemy
{
public:
	Enemy(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
	~Enemy();

	void draw(sf::RenderWindow &window);
	sf::Vector2f getPosition() { return body.getPosition(); }
	Collider getCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
};

#endif
