#include "Animation.hpp"

Animation::Animation(sf::Texture *texture, sf::Vector2u totalImages, float switchTime)
{
	// setting values to variables created in the class
	this->totalImages = totalImages;
	this->switchTime = switchTime;
	// total time is equal to 0 at first
	totalTime = 0.0f;
	// start animation on index 0
	currentImage.x = 0;

	// calculating the height and the width of each image
	uvRect.width = texture->getSize().x / float(totalImages.x);
	uvRect.height = texture->getSize().y / float(totalImages.y);
}

Animation::~Animation()
{

}

// function to update animations
void Animation::update(int row, float deltaTime, bool faceRight)
{
	// sets row on the spritesheet
	currentImage.y = row;
	// increment total time using delta time (this is used, rather than a fixed value so that it runs
	// the same on all computers
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		// instead of setting to 0, we decrement by the switch time so that it's a bit smoother
		totalTime -= switchTime;
		// goes to next image on spritesheet
		currentImage.x++;

		// when it gets to last image on spritesheet go back to first image
		if (currentImage.x >= totalImages.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		// start from the following index
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		// set width to a negative version of the width so that it flips the image around
		uvRect.width = -abs(uvRect.width);
	}
}
