#include "Menu.h"

Menu::Menu(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{ //
	
	object_tex.loadFromFile("Useful/Button/btn.png");
	object.setTexture(&object_tex);
	object.setSize(sf::Vector2f(550.0f, 100.0f));
	object.setOrigin(sf::Vector2f(object.getSize().x/2, object.getSize().y / 2));
	object.setPosition(sf::Vector2f(1920/2 + object.getSize().x /4 , 450.0f));
	
	cursor.setSize(sf::Vector2f(5.0f, 64.0f));
	cursor.setOrigin(sf::Vector2f(2.5f, 32.0f));
	cursor.setPosition(sf::Vector2f(960 - cursor.getGlobalBounds().width/4 , 450.0f));
	cursor.setFillColor(sf::Color::White);

	if (!buffer_mg.loadFromFile("Useful/Sound/main.ogg")) {
		throw "Error";
	}
	sound_mg.setBuffer(buffer_mg);
	font.loadFromFile("Useful/font/Maple/Maplestory Light.ttf");
	bg_.loadFromFile("Useful/MENU/bg.png");
	bg.setTexture(bg_);
	sound_mg.play();
	/*Selector = 0;

	text[0].setFont(font);
	text[0].setString("Play");
	text[0].setFillColor(sf::Color::Red);
	text[0].setPosition(Vector2f(1920 / 2, 1080 / 4 * 1));

	text[1].setFont(font);
	text[1].setString("Score");
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(Vector2f(1920 / 2, 1080 / 4 * 2));

	text[2].setFont(font);
	text[2].setString("Exit");
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(Vector2f(1920 / 2, 1080 / 4 * 3));
	*/

	textbox.setFont(font);
	textbox.setCharacterSize(40);
	textbox.setFillColor(sf::Color::White);
	textbox.setPosition(1920 / 2 - textbox.getGlobalBounds().width / 4, 425);

	
	this->button["NAME"] = new Button(
		1920 / 2-250, 1080 / 4*2 - 100, 150, 50,
		&this->font, "NAME", 30,
		sf::Color(sf::Color::White), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->button["PLAY GAME"] = new Button(
		1920/2, 1080/4*2, 150, 50,
		&this->font, "PLAY GAME", 30,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->button["SCORE"] = new Button(
		1920 / 2, 1080 / 4 * 2.5, 150, 50,
		&this->font, "HIGH SCORE", 30,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->button["EXIT"] = new Button(
		1920 / 2, 1080 / 4 * 3, 150, 50,
		&this->font, "EXIT GAME", 30,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

}

Menu::~Menu() {
	//delete this->button;
	 
	for (auto it = this->button.begin(); it != this->button.end();++it)
	{
		delete it->second;

	}
	
	

}




void Menu::name(sf::Event& event)
{
	if (event.type == sf::Event::EventType::TextEntered)
	{

		if (last_char != event.text.unicode && event.text.unicode == 8 &&
			input.length() > 0) // delete
		{

			last_char = event.text.unicode;
			input.erase(input.length() - 1);
			textbox.setString(input);
			cursor.setPosition(960.0f + textbox.getGlobalBounds().width-10, 450.0f);
			//std::cout << input << std::endl;

		}
		else if (last_char != event.text.unicode &&
			(event.text.unicode >= 'a' && event.text.unicode <= 'z' ||
				event.text.unicode >= 'A' && event.text.unicode <= 'Z' ||
				event.text.unicode >= '0' && event.text.unicode <= '9'))
		{
			//std::cout << event.text.unicode << std::endl;
			last_char = event.text.unicode;

			input += event.text.unicode;

			textbox.setString(input);

			cursor.setPosition(960.0f + textbox.getGlobalBounds().width-10 , 450.0f);

			//std::cout << input << std::endl;
		}

	}

	if (event.type == sf::Event::EventType::KeyReleased && last_char != ' ')
	{
		last_char = ' ';
	}
}

void Menu::update_btn()
{
	for (auto& it : this->button) {
		it.second->update(this->m_posview);
	}

	if (this->button["PLAY GAME"]->isPressed())
	{
		if (input == "\0")
		{
			input = "Player";
		}

		sound_mg.stop();
		this->states->push(new GameState(this->window,this->states,this->input));
		

	}

	if (this->button["SCORE"]->isPressed())
	{
		this->states->push(new HighscoreList(this->window, this->states));

	}

	if (this->button["EXIT"]->isPressed())
	{
		this->quit = true;

	}


}

void Menu::update(const float& deltaTime)
{
	
	if (sound_mg.getStatus() != 2) {
		sound_mg.play();
	}
	
	this->updateMousePOS();
	this->update_btn();
	
	//BUTTON_UPDATE
	
	

}



void Menu::render_btn(RenderTarget* target)
{
	//BUTTON_RENDER
	for (auto& it : this->button) {
		it.second->render(target);
	}



}
 
void Menu::render(RenderTarget* target) {
	
	sf::Event event;

	if (!target)
		target = this->window;
		window->setFramerateLimit(60);
		dt = clock.restart().asSeconds();
		while (this->window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			
			if (event.type == sf::Event::Resized) {
				//Resize_View(window, view);
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				this->window->setView(sf::View(visibleArea));
				break;
			}
		}
		
		this->name(event);
		this->update(dt);
		
		

		//window->clear();

		target->draw(bg);
		

		target->draw(object);
		this->render_btn(target);
		
		if (dt>= 0.5)
		{
			dt = 0;
			state = !state;
		}
		if (state == true)
		{
			target->draw(cursor);
		}

		target->draw(textbox);

		//window->display();

	
	
	
	
	
	
	/*for (int i = 0; i < 3; i++) 
		target->draw(text[i]);*/
	
}

void Menu::endState()
{
}
