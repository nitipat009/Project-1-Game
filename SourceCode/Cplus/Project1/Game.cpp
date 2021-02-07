#include"stdax.h"
#include "Game.h"



void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Mee Game!", sf::Style::Close | sf::Style::Resize);
}

void Game::initState()
{
	this->states.push(new Menu(this->window,&this->states));

}

void Game::initView()
{
	view =  sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920, 1080));
}

Game::Game() // : player(&this->playerTex, sf::Vector2u(6, 6), 0.15f, 300.0f, 1600.0f), b(0.5f)
{
	this->initWindow();
	this->initState();
	

}

Game::~Game()
{
	delete	this->window;
	

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();

	}

}



void Game::endApplication()
{
}

void Game::updateDt()
{
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0 / 20) {
		deltaTime = 1.0 / 20;
	}
}

void Game::updateSFMLEvents()
{
	/*while (this->window->pollEvent(sfEvent))
	{
		switch (sfEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::Resized:
			//Resize_View(window, view);
			sf::FloatRect visibleArea(0, 0, sfEvent.size.width, sfEvent.size.height);
			this->window->setView(sf::View(visibleArea));
			break;

		}
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();

		

	}*/


}

void Game::update()
{
	

	this->updateSFMLEvents();
	

	/*if (sfEvent.type == sf::Event::EventType::TextEntered)
	{

		if (this->last_char != sfEvent.text.unicode && sfEvent.text.unicode == 8 &&
			this->input.length() > 0) // delete
		{

			this->last_char = sfEvent.text.unicode;
			this->input.erase(input.length() - 1);
			this->textbox.setString(input);
			this->cursor.setPosition(650.0f + textbox.getGlobalBounds().width + 5, 450.0f);
			std::cout << input << std::endl;

		}
		else if (this->last_char != sfEvent.text.unicode &&
			(sfEvent.text.unicode >= 'a' && sfEvent.text.unicode <= 'z' ||
				sfEvent.text.unicode >= 'A' && sfEvent.text.unicode <= 'Z' ||
				sfEvent.text.unicode >= '0' && sfEvent.text.unicode <= '9'))
		{
			std::cout << sfEvent.text.unicode << std::endl;
			this->last_char = sfEvent.text.unicode;

			this->input += sfEvent.text.unicode;

			this->textbox.setString(input);

			this->cursor.setPosition(650.0f + this->textbox.getGlobalBounds().width + 5, 450.0f);

			std::cout << input << std::endl;
		}

	}
	if (sfEvent.type == sf::Event::EventType::KeyReleased && this->last_char != ' ')
	{
		this->last_char = ' ';
	}*/
	if (!this->states.empty()) {
		this->states.top()->update(this->deltaTime);

		
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();

		}

	}
	else
	{
		this->window->close();
	}
	



}

void Game::render()
{

	this->window->clear();

	if (!this->states.empty())
	{
		
		this->states.top()->render(this->window);
	}
	

	
	this->window->display();
}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}

}
