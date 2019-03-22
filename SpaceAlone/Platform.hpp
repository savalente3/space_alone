#ifndef Platform_hpp
#define Platform_hpp

#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class Platform
{
public:
	Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();

	void draw(sf::RenderWindow &window);
	sf::Vector2f getPosition() { return body.getPosition(); }
	Collider getCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
};

#endif
