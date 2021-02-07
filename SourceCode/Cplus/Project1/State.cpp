#include "State.h"

State::State(sf::RenderWindow*window, std::stack<State*>* states)
{
	this->window = window;
	this->states = states;
	this->quit = false;
	this->paused = false;
	
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
	
}

void State::endState()
{
}

void State::updateMousePOS()
{
	this->m_posscreen = sf::Mouse::getPosition();
	this->m_poswin = (sf::Vector2f)sf::Mouse::getPosition(*this->window);
	this->m_posview = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
	

}



void State::update(const float& deltaTime)
{
}

void State::render(sf::RenderTarget* target)
{
}

void State::check_quit()
{
	

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
	{
		
		this->quit = true;
		
	
	}
	
}
void State::check_pause()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		check_push = true;
	}
	else 
	{
		check_push = false;
		check_status = false;
	}
	if (check_push == true && check_status == false)
	{
		check_status = true;

		
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}

	

}

void State::pauseState()
{
	this->paused = true;
}

void State::diedState()
{
	this->died = true;
}

void State::unpauseState()
{
	this->paused = false;
}