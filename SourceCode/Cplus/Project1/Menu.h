#pragma once
#ifndef MENU_H
#define MENU_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include "State.h"
#include"GameState.h"
#include "Button.h"
#include"HighscoreManager.h"
#include"HighscoreList.h"


using namespace sf;
using namespace std;

class Menu:
	public State
{
	private :
		Font font;
		Text text[3];
		Texture bg_;
		Sprite bg;
		View view;
		Texture object_tex;
		//sf::Event sfEvent;
		float totalTime = 0;
		bool state = false;
		char last_char = ' ';
		std::string input;
		std::map<std::string, Button*>button;
		Text textbox;
		float dt;
		sf::Sound sound_mg;
		sf::SoundBuffer buffer_mg;

		
		
		
	public :
		
		
		sf::RectangleShape object;
		sf::RectangleShape cursor;
		
		sf::Clock clock;
		
		HighscoreManager h;
		Menu(sf::RenderWindow* window, std::stack<State*>* states);
		virtual~Menu();
	
		void name(sf::Event &event);
		void update_btn();
		void update(const float& deltaTime);
		
		void render_btn(RenderTarget* target);
		void render(RenderTarget* target);

		void endState();


};

#endif