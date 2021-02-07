#ifndef STATE_H
#define STATE_H

#include"stdax.h"

class State
{
private:
	bool check_push = false;
	bool check_status = false;

public:
	
	std::stack<State*> *states;
	State(sf::RenderWindow* window, std::stack<State*>* states);
	sf::RenderWindow* window;
	bool quit;
	bool paused;
	bool died;
	bool victory = false;
	

	sf::Vector2i m_posscreen ;
	sf::Vector2f m_poswin;
	sf::Vector2f m_posview;

	virtual ~State();
	
	const bool& getQuit() const;

	virtual void endState() = 0;
	virtual void updateMousePOS();
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

	virtual void check_quit();
	virtual void check_pause();
	
	void pauseState();
	void diedState();
	void unpauseState();

};

#endif