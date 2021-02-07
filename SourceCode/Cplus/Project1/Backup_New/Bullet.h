#pragma once
#include "SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"Player.h"
#include<vector>
#include<math.h>


using namespace sf;
class Bullet
{
public:
	
	sf::CircleShape shape;
	sf::Vector2f currVelocity;
	float maxSpeed;
	int bulletClip=30;

	Bullet(float radius = 5.0f) :
		currVelocity(0.0f, 0.0f), maxSpeed(15.0f)
	{
		this->shape.setRadius(radius);
	}



	float mCooldown = 0.2;
	
	
	void Update(RenderWindow& window,Player player);
	void Render(RenderWindow& window);
private:
	
	
};