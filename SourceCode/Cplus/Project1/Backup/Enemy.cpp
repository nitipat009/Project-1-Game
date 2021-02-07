#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	
	row = 0;
	isLeft = true;
	

	body.setSize(sf::Vector2f(256.0f, 256.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(400, 520);
	body.setTexture(texture);
	body.setOutlineColor(sf::Color::Red);
	body.setOutlineThickness(5.0f);

}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{
	


	if (velocity.x == 0.0f) {
		row = 1;

	}
	else
	{
		row = 1;

		if (velocity.x > 0.0f) {
			isLeft = false;
		}
		else
			isLeft = true;
	}
	


	animation.Update(row, deltaTime, isLeft,true);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);

}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Enemy::Oncolision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		attack = true;
		//Coliision On Left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//RIGHT
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//bottom
		velocity.y = 0.0f;
		
	}
	else if (direction.y > 0.0f)
	{
		//Top
		velocity.y = 0.0f;

	}
}
