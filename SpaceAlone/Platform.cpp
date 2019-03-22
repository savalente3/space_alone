#include "Platform.hpp"

Platform::Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setTexture(texture);
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
}

Platform::~Platform()
{

}

void Platform::draw(sf::RenderWindow &window)
{
	window.draw(body);
}
