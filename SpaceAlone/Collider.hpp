#ifndef Collider_hpp
#define Collider_hpp

#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape &body);
	~Collider();

	bool checkCollision(Collider &other, float push);

	// so we don't have to make body a public variable
	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getHalfSize() { return body.getSize() / 2.0f; }
	void move(float deltaX, float deltaY) { body.move(deltaX, deltaY); }

private:
	sf::RectangleShape &body;

};

#endif
