#include "Menu.h"

Menu::Menu(float width, float height) {
	font.loadFromFile("lucon.ttf");
	bg_.loadFromFile("CharacterSpriteSheet/background/background menu.jpg");
	bg.setTexture(bg_);

	Selector = 0;

	text[0].setFont(font);
	text[0].setString("Play");
	text[0].setFillColor(sf::Color::Red);
	text[0].setPosition(Vector2f(width / 2, height / 4 * 1));

	text[1].setFont(font);
	text[1].setString("Score");
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(Vector2f(width / 2, height / 4 * 2));

	text[2].setFont(font);
	text[2].setString("Exit");
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(Vector2f(width / 2, height / 4 * 3));
}

Menu::~Menu() {

}

void Menu::MoveDown() {
	if (Selector != 3) {
		switch (Selector) {
			case 0 :
				text[Selector].setColor(Color::White);
				Selector++;
				text[Selector].setColor(Color::Red);
				break;
			case 1 :
				text[Selector].setColor(Color::White);
				Selector++;
				text[Selector].setColor(Color::Red);
				break;
		}

	}
}

void Menu::MoveUp() {
	if (Selector != 0) {
		switch (Selector) {
			case 1 :
				text[Selector].setColor(Color::White);
				Selector--;
				text[Selector].setColor(Color::Red);
				break;
			case 2 :
				text[Selector].setColor(Color::White);
				Selector--;
				text[Selector].setColor(Color::Red);
				break;
		}
	}

}

void Menu::Render(RenderTarget& target) {
	target.draw(bg);
	for (int i = 0; i < 3; i++) target.draw(text[i]);
}
