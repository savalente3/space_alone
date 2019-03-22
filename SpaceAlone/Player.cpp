#include "Player.hpp"

Player::Player(sf::Texture *texture, sf::Vector2u totalImages, float switchTime, float speed, float jumpHeight)
	: animation(texture, totalImages, switchTime) // initializer for the animation class
{
	// set values to the class variables
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	// creating the actual rectangle and setting values to it
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
	// slowly stops body when release a button
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
		// move left
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		// move right
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		// so we cant jump more than once
		canJump = false;
		// does the opposite of the gravity variable, so allows us to jump
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}
	// equation to add gravity to body
	velocity.y += 981.0f * deltaTime;

	// we're not moving, so shows images on firt row of spritesheet (idle)
	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		// once we move, we show image on second row (walk)
		row = 1;

		// if movement to the right, texture facing right
		if (velocity.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			// if movement to the left, texture facing left
			faceRight = false;
		}
	}

	// calls animation update method to animate the body
	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::draw(sf::RenderWindow &window)
{
	window.draw(body);
}

// deals with collisions depending on which side we're touching
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
