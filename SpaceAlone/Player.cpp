#include "Player.hpp"

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) : animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(80.0f, 110.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(500.0f, 300.0f);
	body.setTexture(texture);
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	velocity.x *= 0.2f;

	// Joystick movement 

	if (sf::Joystick::isButtonPressed(0, 0) && canJump) {
		canJump = false;

		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < 0)
	{
		velocity.x -= speed;
	}

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > 0)
	{
		velocity.x += speed;
	}
	
	// end of joystick movement

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;

		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (velocity.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}

	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::draw(sf::RenderWindow &window)
{
	window.draw(body);
}

void Player::onCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		// left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		// right
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		// bottom
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		// top
		velocity.y = 0.0f;
	}
}
