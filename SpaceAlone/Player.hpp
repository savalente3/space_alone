#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collider.hpp"

class Player
{
public:
	Player(sf::Texture *texture, sf::Vector2u totalImages, float switchTime, float speed, float jumpHeight);
	~Player();

	sf::Vector2f getPosition() { return body.getPosition(); }
	// update the animation
	void update(float deltaTime);
	// so that we can keep the body private
	void draw(sf::RenderWindow &window);
	void onCollision(sf::Vector2f direction);

	Collider getCollider() { return Collider(body); }

private:
	// body of the player
	sf::RectangleShape body;
	// in order to add animations
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};
#endif
