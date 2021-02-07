#include "Colision.h"


Colision::Colision(sf::RectangleShape& body) :
	body(body)
{

}

Colision::~Colision()
{
}

bool Colision::CheckCollision(Colision other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize =	GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float IntersectX = abs(deltaX) - (otherHalfSize.x/2 + thisHalfSize.x);
	float IntersectY = abs(deltaY) - (otherHalfSize.y/2.5 + thisHalfSize.y);

	if (IntersectX < 0.0f && IntersectY < 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (IntersectX > IntersectY)
		{
			if (deltaX > 0.0f) {
				Move(IntersectX * (1.0f - push), 0.0f);
				other.Move(-IntersectX * push, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;

			}
			else
			{
				Move(IntersectX * (1.0f - push), 0.0f);
				other.Move(IntersectX * push, 0.0f);
				direction.x = -1.0f;
				direction.y = 0.0f;

			}

		}
		else {
			if (deltaY > 0.0f) {
				Move(0.0f, IntersectY * (1.0f - push));
				other.Move(0.0f, -IntersectY * push);
				direction.x = 0.0f;
				direction.y = 1.0f;


			}
			else
			{
				Move(0.0f, IntersectY * (1.0f - push));
				other.Move(0.0f, IntersectY * push);
				direction.x = 0.0f;
				direction.y = -1.0f;

			}


		}

		return true;
	}


	return false;
}
