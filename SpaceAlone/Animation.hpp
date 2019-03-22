#ifndef Animation_hpp
#define Animation_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture *texture, sf::Vector2u totalImages, float switchTime);
	~Animation();

	void update(int row, float deltaTime, bool faceRight);

	sf::IntRect uvRect;

private:
	sf::Vector2u totalImages;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

#endif
