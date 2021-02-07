#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;

class Menu
{
	private :
		Font font;
		Text text[3];
		Texture bg_;
		Sprite bg;
		
	public :
		int Selector;

		Menu(float width, float height);
		~Menu();
		void MoveDown();
		void MoveUp();
		void Render(RenderTarget& target);
};

