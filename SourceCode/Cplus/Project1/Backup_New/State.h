#ifndef STATE_H
#define STATE_H

#include"stdax.h"

class State
{
private:
	sf::RenderWindow* window;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void endState() = 0;

	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target) = 0;

};

#endif