#pragma once
#ifndef HIGHSCORELIST_H
#define HIGHSCORELIST_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include "State.h"
#include "Button.h"

using namespace sf;
using namespace std;



class HighscoreList :
	public State
{

	
	private:
	Font font;
	std::map<std::string, Button*>button;
	static bool sortScoreDesc(const sf::Vector2<int>& a, const sf::Vector2<int>& b);
	sf::Texture tex_bg;
	sf::Sprite m_bg; ///< the background to display

	Text m_name; ///< to display the score
	Text m_points; ///< To display the points
	

	std::map<int, std::string>::iterator end;
	std::map<int, std::string>::iterator beg;
	
	std::vector<int> num_stored;
	map<int, string> stored;
	int currentDisplay = 0;
	std::fstream file;
	std::string word;



	public:

	HighscoreList(sf::RenderWindow* window, std::stack<State*>* states);
	virtual~HighscoreList();
	void initHighscoreList();
	void update_btn();
	void update(const float& deltaTime);

	void render_score(RenderTarget* target);
	void render(RenderTarget* target);

	void endState();

};

#endif




