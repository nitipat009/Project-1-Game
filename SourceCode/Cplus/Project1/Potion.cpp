#include "Potion.h"

Potion::Potion(sf::Texture* Texture, sf::Vector2f size, sf::Vector2f position,int heal)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(Texture,true);
	
	body.setPosition(position);
	this->health = heal;
}

Potion::~Potion()
{
	
}

void Potion::Update(float deltaTime)
{
	velocity.x = 0;
	
	velocity.y += 981.0f * deltaTime; // ¢Í§µ¡
	body.move(velocity);
}

void Potion::Draw(sf::RenderWindow* window)
{
	window->draw(this->body);

}

void Potion::Oncolision(sf::Vector2f direction)
{
	if (direction.y < 0.0f)
	{
		//bottom
		velocity.y = 0.0f;
		
	}

}

int Potion::generateRandom(int max)
{
	srand(1);
	int randomnumber = rand();
	float random = (randomnumber % max) + 1;
	int myrandom = random;

	return myrandom;
}