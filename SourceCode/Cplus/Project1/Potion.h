#pragma once
#include<SFML/Graphics.hpp>
#include"Colision.h"
class Potion
{
private:

	
	




public:
	//Variable
	int health;
	sf::Vector2f velocity;
	sf::RectangleShape body;

	Potion(sf::Texture* Texture, sf::Vector2f size, sf::Vector2f position,int heal);
	~Potion();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void Oncolision(sf::Vector2f direction);

	int generateRandom(int max);
	Colision GetColision() { return Colision(body); }

};

