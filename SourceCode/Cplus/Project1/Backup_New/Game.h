#ifndef GAME_H
#define GAME_H
#include"stdax.h"
#include "State.h"


class Game
{
private:
	//Variables
	std::stack<State*> states;

	sf::RenderWindow* window;
	sf::View view;
	sf::Event sfEvent;
	sf::Clock clock;
	sf::Clock pClock;
	sf::Text Score;
	sf::Texture playerTex;
	//----------BULLET
	sf::Sprite bullet;
	sf::Texture tex;
	sf::Sound sound_shoot;
	sf::SoundBuffer buffer_shoot;


	std::vector<Bullet> bullets;

	Vector2f playerCenter, mousePos, aimDir;
	//----------BULLET

	//---------HEALTH BAR-------------//
	sf::Texture HPbar;
	sf::Sprite hpbar;
	int MyHP = 0;
	sf::RectangleShape HP;
	int score_point = 0;

	//---------HEALTH BAR-------------//


	//-------ENEMY--------//
	sf::Texture enemy_tex;
	
	sf::Vector2u textureSize;
	sf::IntRect rect;



	//SOUND//

	sf::SoundBuffer buffer_back, buffer_hited, buffer_zomhit;
	sf::Sound sound;
	sf::Sound sound_hitted, sound_zomhit;

	//BACKGROUND//
	sf::Texture BackgroundTexture[2];
	sf::Sprite background, background_d;
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.


	//------------------GROUND------------------------//
	sf::Texture ground_Texture;
	sf::Sprite ground;
	
	




	std::vector<Platform> platforms;


	float View_Height = 1080, View_Width = 1920;
	float deltaTime = 0.0f;
	const float aspectRatio = 1.78;
	bool colider;
	bool canfire = true;

	void Resize_View(const sf::RenderWindow& window, sf::View& view);

	void mouse_cursor(sf::RenderWindow* window);

	void player_gui(sf::RenderWindow* window, Player* player, int score_point);

	Player *player;
	Bullet b;

	
	void inithp();
	void initState();
	void initWindow();
	void initView();
	

public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	void Loader();


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