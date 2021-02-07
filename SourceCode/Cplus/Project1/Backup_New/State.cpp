#include "State.h"

State::State(sf::RenderWindow*window)
{
	this->window = window;
}

State::~State()
{
}

void State::endState()
{
}

void State::update(const float& deltaTime)
{
}

void State::render(sf::RenderTarget* target)
{
}
