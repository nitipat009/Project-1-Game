#include "Enenmy.h"


Enenmy::Enenmy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position,sf::Vector2f size)
	: animation(texture, imageCount, switchTime, true), player(texture, imageCount, switchTime, speed,  400.0f)
{
	this->speed = speed;
	health = 100;
	row = 0;
	isLeft = false;


	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
	healthbar = sf::RectangleShape(sf::Vector2f(health, 10));
	healthbar.setOrigin(healthbar.getSize() / 2.0f);
	healthbar.setFillColor(sf::Color::Red);
	
	/*body.setOutlineColor(sf::Color::Red);
	body.setOutlineThickness(5.0f);*/
}

Enenmy::~Enenmy()
{
}

void Enenmy::Update(float deltaTime)
{

	healthbar.setPosition(body.getPosition().x, body.getPosition().y + 50);
	healthbar.setSize(sf::Vector2f(health,10));
	//velocity.x = 0.0f;
	//velocity.y += 981.0f * deltaTime;
		row = 0;

		if (velocity.x > 0.0f) {
			isLeft = false;
		}
		else
			isLeft = true;
	

	animation.Update(row, deltaTime, isLeft,true);
	body.setTextureRect(animation.uvRect);
	body.move(velocity);
}

void Enenmy::Draw(sf::RenderWindow* window)
{
	window->draw(body);
	window->draw(healthbar);

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
