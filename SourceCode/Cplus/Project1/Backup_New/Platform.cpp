#include "Platform.h"

Platform::Platform(sf::Texture* Texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	
	body.setOrigin(size/2.0f);
	body.setTexture(Texture);
	
	body.setTextureRect(sf::IntRect(0, 0, 800,200));
	
	body.setPosition(position);
	//body.setFillColor(sf::Color::Red);
	/*body.setOutlineColor(sf::Color::Red);
	body.setOutlineThickness(5.0f);*/
}

Platform::~Platform()
{
}


void Platform::Draw(sf::RenderTarget* window)
{
	window->draw(this->body);
}
