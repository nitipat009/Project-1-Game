#pragma once
#include"SFML/Graphics.hpp"
#include"Animation.h"
#include"Colision.h"

class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Enemy();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void Oncolision(sf::Vector2f direction);

	sf::Vector2f GetPosition() {

		return body.getPosition();
	}

	

	sf::FloatRect GetRect() {

		return body.getGlobalBounds();
	}

	void setPosition(float x, float y) {

		return body.setPosition(x, y);
	}

	Colision GetColision() { return Colision(body); }

private:

	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool isLeft;
	float jumpHeight;
	bool attack = false;
	sf::Vector2f velocity;


};

