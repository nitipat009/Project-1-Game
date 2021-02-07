#include "PauseMenu.h"


void PauseMenu::addButton(const std::string key, float y, const std::string text)
{
	
	this->button[key] = new Button(
		x, y, 250.f, 50.0f,
		&this->font, text, 30,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);
}

PauseMenu::PauseMenu(sf::RenderWindow& window, sf::Font& font):
	font(font)
{
	
	this->bg.setSize(sf::Vector2f(
		static_cast<float>(window.getSize().x), 
		static_cast<float>(window.getSize().y)));
	this->bg.setFillColor(sf::Color(20, 20, 20, 100));

	this->container.setSize(sf::Vector2f(
		static_cast<float>(window.getSize().x) / 4.f,
		static_cast<float>(window.getSize().y) - 100.f
		)
	);

	this->container.setFillColor(sf::Color(20, 20, 20, 100));
	this->container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x /2.f,
		30.f);

	//Init text
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(60);
	this->menuText.setString("PAUSED");
	this->menuText.setPosition(
		this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y
	);


}

PauseMenu::~PauseMenu()
{
	for (auto it = this->button.begin(); it != this->button.end(); ++it)
	{
		delete it->second;

	}
}

std::map<std::string, Button*>& PauseMenu::getButtons()
{
	return this->button;
	// TODO: insert return statement here
}

const bool PauseMenu::isButtonPressed(const std::string key)
{
	return this->button[key]->isPressed();
	// TODO: insert return statement here
}



void PauseMenu::update(sf::Vector2f position,sf::Vector2f& mousePos)
{
	bg.setPosition(position.x-960, 0);
	container.setPosition(position.x - container.getGlobalBounds().width/2 ,100.0f);
	menuText.setPosition(
		this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y
	);
	

	for (auto& i : this->button)
	{
		button["EXIT_MENU"]->setPosition(sf::Vector2f
		(this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f,
		this->container.getPosition().y+750.0f));

		i.second->update(mousePos);
	}
	
}

void PauseMenu::render(sf::RenderTarget* target)
{
	target->draw(this->bg);
	target->draw(this->container);

	for (auto& i : this->button)
	{
		i.second->render(target);
	}
	target->draw(this->menuText);
}
