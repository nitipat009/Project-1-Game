#ifndef DEADMENU_H
#define DEADMENU_H
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<stack>
#include "Button.h"
#include"HighscoreManager.h"
#include"IOHighscore.h"

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Network.hpp"
#include"SFML/Audio.hpp"

class DeadMenu
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
	
	std::stringstream nameStream;
	std::stringstream pointsStream;
	

public:
	
	DeadMenu(sf::RenderWindow& window, sf::Font& font);
	virtual ~DeadMenu();
	std::map<std::string, Button*>& getButtons();
	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key, float y, const std::string text);
	void update(sf::Vector2f position, sf::Vector2f& mousePos,bool victory);
	void render(sf::RenderTarget* target);
};

#endif