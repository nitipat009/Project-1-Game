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
	sf::CircleShape range;
	sf::CircleShape b_range;

	sf::Vector2f currVelocity,enemy_v,boss_v;
	float maxSpeed;
	int bulletClip=30;

	Bullet(float radius = 5.0f) :
		currVelocity(0.0f, 0.0f), maxSpeed(15.0f) , enemy_v(0.0f,0.0f) , boss_v(0.0f,0.0f)
	{
		this->shape.setRadius(radius);
		this->range.setRadius(20.0f);
		this->b_range.setRadius(20.0f);
	}



	float mCooldown = 0.5;
	
	
	void Update(RenderWindow& window,Player player);
	void Render(RenderWindow& window);
private:
	
	
};