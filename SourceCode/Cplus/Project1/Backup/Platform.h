#pragma once
#include"SFML/Graphics.hpp"
#include"Colision.h"
class Platform
{
public:
	Platform(sf::Texture* Texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();
	void Draw(sf::RenderWindow& window);

	Colision GetCollider() { return Colision(body); }

private :
	sf::RectangleShape body;
};

