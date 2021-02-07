#pragma once
#include"SFML/Graphics.hpp"

class Animation
{
public:
	Animation(sf::Texture* texture,sf ::Vector2u imageCount,float switchTime,bool enemy);
	~Animation();

	void Update(int row, float deltaTime , bool isLeft, bool enemy);



public:
	sf::IntRect uvRect;

private:
	//sf::IntRect recta;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
	bool enemy;
	

};

