#include "Collider.hpp"

Collider::Collider(sf::RectangleShape &body) : body(body)
{

}

Collider::~Collider()
{

}

bool Collider::checkCollision(Collider &otherBody, sf::Vector2f &direction, float push)
{
	// get other position and halfsize
	sf::Vector2f otherPosition = otherBody.getPosition();
	sf::Vector2f otherHalfSize = otherBody.getHalfSize();
	// get my postion and halfsize
	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisHalfSize = getHalfSize();

	// get the difference of position on the x axis and y axis
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	// calculates the intersection values
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	// if they're colliding
	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		// clamp the push position to 0 and 1
		push = std::min(std::max(push, 0.0f), 1.0f);

		// check which intersection is bigger to push on the right axis
		if (intersectX > intersectY)
		{
			// if it's intersecting on the left, push body to the right and other to the left
			if (deltaX > 0.0f)
			{
				move(intersectX * (1.0f - push), 0.0f);
				otherBody.move(-intersectX * push, 0.0f);

				direction.x = 1.0f;
				// no change on y axis
				direction.y = 0.0f;
			}
			else
			{
				// if it's intersecting on the right, push body to the left and other to the right

				move(-intersectX * (1.0f - push), 0.0f);
				otherBody.move(intersectX * push, 0.0f);

				direction.x = -1.0f;
				// no change on y axis
				direction.y = 0.0f;
			}
		}
		else
		{
			// if it's intersecting on the bottom, push body up and other down
			if (deltaY > 0.0f)
			{
				move(0.0f, intersectY * (1.0f - push));
				otherBody.move(0.0f, -intersectY * push);

				// no change on x axis
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else
			{
				// if it's intersecting on the top, push body down and other up
				move(0.0f, -intersectY * (1.0f - push));
				otherBody.move(0.0f, intersectY * push);

				// no change on x axis
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		// yes they're intersecting return true
		return true;
	}
	// they're no longer intersecting, return false
	return false;
}
