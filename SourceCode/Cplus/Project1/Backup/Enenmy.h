#pragma once
#include"SFML/Graphics.hpp"
#include"Animation.h"
#include"Colision.h"
#include"Player.h"

class Enenmy
{public:
	sf::RectangleShape body;
	Enenmy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position);
	~Enenmy();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void Oncolision(sf::Vector2f direction);
	sf::Vector2f velocity;
	sf::Vector2f GetPosition() {

		return body.getPosition();
	}

	sf::Vector2f GetRadius() {



	}

	sf::FloatRect GetRect() {

		return body.getGlobalBounds();
	}

	void setPosition(float x, float y) {

		return body.setPosition(x, y);
	}

	void move(float x, float y) {
		body.move(x, y);

	}

	Colision GetColision() { return Colision(body); }

private:
	
	Animation animation;
	Player player;
	unsigned int row;
	float speed;
	bool isLeft;
	

};
