#include "NameState.h"

NameState::NameState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	object.setSize(sf::Vector2f(300.0f, 70.0f));
	object.setOrigin(sf::Vector2f(150.0f, 35.0f));
	object.setPosition(sf::Vector2f(800, 450.0f));

	cursor.setSize(sf::Vector2f(5.0f, 64.0f));
	cursor.setOrigin(sf::Vector2f(2.5f, 32.0f));
	cursor.setPosition(sf::Vector2f(655, 450.0f));
	cursor.setFillColor(sf::Color::Black);

	font.loadFromFile("Useful/font/Maple/Maplestory Light.ttf"); //// <- Enter font here

	
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setPosition(650, 425);

}

NameState::~NameState()
{
}

void NameState::endState()
{
}

void NameState::update(const float& deltaTime)
{
	if (event->type == sf::Event::EventType::TextEntered)
	{

		if (last_char != event->text.unicode && event->text.unicode == 8 &&
			input.length() > 0) // delete
		{

			last_char = event->text.unicode;
			input.erase(input.length() - 1);
			text.setString(input);
			cursor.setPosition(650.0f + text.getGlobalBounds().width + 5, 450.0f);
			std::cout << input << std::endl;

		}
		else if (last_char != event->text.unicode &&
			(event->text.unicode >= 'a' && event->text.unicode <= 'z' ||
				event->text.unicode >= 'A' && event->text.unicode <= 'Z' ||
				event->text.unicode >= '0' && event->text.unicode <= '9'))
		{
			//std::cout << event.text.unicode << std::endl;
			last_char = event->text.unicode;

			input += event->text.unicode;

			text.setString(input);

			cursor.setPosition(650.0f + text.getGlobalBounds().width + 5, 450.0f);

			std::cout << input << std::endl;
		}

	}

	if (event->type == sf::Event::EventType::KeyReleased && last_char != ' ')
	{
		last_char = ' ';
	}


}

void NameState::render(sf::RenderTarget* target)
{
	totalTime += clock.restart().asSeconds();
	if (totalTime >= 0.5)
	{
		totalTime = 0;
		state = !state;
	}
	if (state == true)
	{
		target->draw(cursor);
	}

	target->draw(text);

}
