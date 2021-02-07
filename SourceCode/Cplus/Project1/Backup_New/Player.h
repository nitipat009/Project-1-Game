#pragma once
#include"SFML/Graphics.hpp"
#include"Animation.h"
#include"Colision.h"


class Player

{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed ,float jumpHeight);
	~Player();
	sf::RectangleShape body;
	void Update(float deltaTime);
	void Draw(sf::RenderTarget* window);
	void Oncolision(sf::Vector2f direction);
	
	sf::Vector2f GetPosition() {
		
		return body.getPosition();
	}

	sf::Vector2f GetRadius() {
	
	
	
	}

	sf::FloatRect GetRect() {
	
		return body.getGlobalBounds();
	}

	void setPosition(float x,float y) {
	
		return body.setPosition(x, y);
	}

	sf::Vector2f velocity;

	Colision GetColision() { return Colision(body); }
	
private:

	
	Animation animation;
	unsigned int row;
	float speed;
	bool isLeft;
	float jumpHeight;
	bool canjump;
	
	

};

