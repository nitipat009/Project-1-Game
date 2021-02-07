#ifndef GAME_H
#define GAME_H
#include"stdax.h"
#include "GameState.h"
#include "Menu.h"

class Game
{
private:
	//Variables
	std::stack<State*> states;
	//Menu* menu;
	sf::RenderWindow* window;
	sf::View view;
	
	sf::Clock clock;
	sf::Clock pClock;
	float deltaTime;
	

	void initState();
	void initWindow();
	void initView();
	

public:
	int state = 0;
	sf::Event sfEvent;
	
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	
	

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};
#endif