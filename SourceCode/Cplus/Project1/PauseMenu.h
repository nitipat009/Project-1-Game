#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<stack>
#include "Button.h"

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Network.hpp"
#include"SFML/Audio.hpp"


class PauseMenu
{
private:
	sf::Font& font;
	sf::Text menuText;
	sf::RectangleShape bg;
	sf::RectangleShape container;
	float width = 250.0f;
	float height = 50.0;
	float x;

	std::map<std::string, Button*>button;

public:
	PauseMenu(sf::RenderWindow&window,sf::Font &font);
	virtual ~PauseMenu();
	std::map<std::string, Button*>& getButtons();
	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key,float y,const std::string text);
	void update(sf::Vector2f position, sf::Vector2f& mousePos);
	void render(sf::RenderTarget* target);
	
};

#endif