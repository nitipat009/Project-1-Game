#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	 animation(texture, imageCount,switchTime,false)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	isLeft = true;
	canjump = true;
	
	body.setSize(sf::Vector2f(150.0f, 150.f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(570, 800);
	body.setTexture(texture);
	/*body.setOutlineColor(sf::Color::Green);
	body.setOutlineThickness(5.0f);*/
	
}

Player::~Player()
{
	
}

void Player::Update(float deltaTime)
{
	const float ground = 550;

	velocity.x = 0.0f;
	

	//sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		//isWalk = true;
		velocity.x -= speed;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		//isWalk = true;
		velocity.x += speed;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canjump == true)
	{
		canjump = false;
		velocity.y = -sqrtf(2.0f * 98.1f * jumpHeight);

	}


	
	velocity.y += 981.0f * deltaTime;
	
	
	
	
	
	


	if (velocity.x == 0.0f) {
		row = 0;
	
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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		row = 2;

	}


	animation.Update(row, deltaTime, isLeft,false);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);

}

void Player::Draw(sf::RenderTarget* window)
{

	window->draw(this->body);
}

void Player::Oncolision(sf::Vector2f direction)
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
		canjump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Top
		velocity.y = 0.0f;
		
	}
	
		
	
		
}
