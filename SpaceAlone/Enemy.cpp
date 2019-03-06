#include "Enemy.hpp"

Enemy::Enemy(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setTexture(texture);
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
}

Enemy::~Enemy()
{

}

void Enemy::draw(sf::RenderWindow &window)
{
	window.draw(body);
}
