#include "Enenmy.h"


Enenmy::Enenmy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position)
	: animation(texture, imageCount, switchTime, true) , player(texture, imageCount, switchTime, speed,  400.0f)
{
	this->speed = speed;
	
	row = 0;
	isLeft = false;


	body.setSize(sf::Vector2f(248.4f, 253.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
	/*body.setOutlineColor(sf::Color::Red);
	body.setOutlineThickness(5.0f);*/
}

Enenmy::~Enenmy()
{
}

void Enenmy::Update(float deltaTime)
{

	
	
	velocity.y += 981.0f * deltaTime;
		row = 0;

		if (velocity.x > 0.0f) {
			isLeft = true;
		}
		else
			isLeft = false;
	

	animation.Update(row, deltaTime, isLeft,true);
	body.setTextureRect(animation.uvRect);
	body.move(velocity);
}

void Enenmy::Draw(sf::RenderWindow& window)
{
	window.draw(body);

}

void Enenmy::Oncolision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
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
