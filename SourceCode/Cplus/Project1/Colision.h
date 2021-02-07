#pragma once
#include"SFML/Graphics.hpp"

class Colision
{
public:
	Colision(sf::RectangleShape & body);
	~Colision();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(Colision other, sf::Vector2f& direction, float push, bool enemy);
		sf::Vector2f GetPosition() { return body.getPosition(); }
		sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f;}

private:
		sf::RectangleShape& body;
};

