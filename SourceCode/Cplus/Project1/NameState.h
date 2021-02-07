#ifndef NAMESTATE_H
#define NAMESTATE_H
#include "State.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>
#include<stack>



#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include<SFML/Graphics.hpp>

class NameState :
	public State
{
private:

	sf::RectangleShape object;
	sf::Event* event;
	sf::RectangleShape cursor;
	sf::Font font;
	sf::Text text;

	float totalTime = 0;
	sf::Clock clock;
	bool state = false;

	char last_char = ' ';

	std::string input;

	



public:
	NameState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~NameState();

	void endState();


	//Update
	void update(const float& deltaTime);
	//Render
	void render(sf::RenderTarget* target);




};



#endif