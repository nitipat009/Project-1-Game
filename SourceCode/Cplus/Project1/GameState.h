#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include"GameState2.h"
//#include "Menu.h"


class GameState:
	public State
{
private:
	//Variables
	bool direct;
	int score_point;
	IOHighscore iohighscore;
	HighscoreManager highscore;
	std::string hName;
	bool highscoreWritten;
	int stage;
	sf::View view;
	sf::Clock clock;
	sf::Clock pClock;
	sf::Clock change_map;
	Clock spawn_time,spawn_time3;
	Clock e_cooldown,boss_c;
	sf::Text Score;
	sf::Texture playerTex;
	//----------BULLET
	sf::Sprite bullet;
	sf::Texture tex,laser,boss_laser;
	sf::Sound sound_shoot;
	sf::SoundBuffer buffer_shoot,buffer_mg;
	PauseMenu* pmenu;
	DeadMenu* dmenu;
	
	//-------POTION
	Potion* potion;
	std::vector<Potion> potions,potions2,potions3;
	sf::Texture potion_tex, potion_tex2, potion_tex3;
	std::vector<Bullet> bullets,range_,bosses_b;

	Vector2f playerCenter, mousePos, aimDir;
	//----------BULLET

	//---------HEALTH BAR-------------//
	sf::Texture HPbar;
	sf::Sprite hpbar;
	
	sf::RectangleShape HP;
	

	//---------HEALTH BAR-------------//


	//-------ENEMY--------//
	sf::Texture enemy_tex;
	sf::Texture enemy_tex3;
	sf::Texture boss_tex1;
	sf::Texture boss_tex2;

	bool boss_spawn = false;
	bool boss2_spawn = false;
	bool boss_death = false;
	bool boss2_death = false;
	sf::Vector2u textureSize;
	sf::IntRect rect;



	//SOUND//

	sf::SoundBuffer buffer_back, buffer_hited, buffer_zomhit;
	sf::Sound sound;
	sf::Sound sound_hitted, sound_zomhit;

	//BACKGROUND//
	sf::Texture BackgroundTexture[2];
	sf::Texture bg_starTex,bg_moonTex, bg_cloudTex,bg_cloud1Tex,bg_cloud2Tex,bg_treeTex;
	sf::Sprite bg_star, bg_moon, bg_cloud, bg_cloud1, bg_cloud2, bg_tree;
	sf::Sprite background, background_d;
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.
	sf::Texture bg_vicTex;
	sf::Sprite bg_vic;


	//------------------GROUND------------------------//
	sf::Texture ground_Texture;
	sf::Texture ground_upTex;
	sf::Sprite ground;






	std::vector<Platform> platforms;
	std::vector<Enenmy> enemies,enemies3,bosses1,bosses2;
	
	float View_Height = 1080, View_Width = 1920;
	float deltaTime = 0.0f;
	const float aspectRatio = 1.78;
	bool colider[3];
	bool canfire = true;
	bool check = false;
	sf::Font font;
	void Resize_View(const sf::RenderWindow& window, sf::View& view);

	void mouse_cursor(sf::RenderWindow* window);

	void player_gui(sf::RenderWindow* window, Player* player, int score_point);


	Player* player;
	Enenmy* enemy;
	Bullet b;

	void spawn(sf::Vector2f player);
	void spawn3(sf::Vector2f player);
	void boss1(sf::Vector2f player);
	void boss2(sf::Vector2f player);

	void big_potion(sf::Vector2f position);
	void master_potion(sf::Vector2f position);
	void small_potion(sf::Vector2f position);

	void enemy_act();
	void boss_act();
	void map_update();
	void inithp();
	void initState();
	void initView();
	void updatePauseMenuButtons();

public:
	//Constructors/Destructors
	GameState(sf::RenderWindow* window, std::stack<State*>* states,std::string name);
	virtual ~GameState();

	//Functions
	void Loader();

	void endState();
	

	//Update
	void update(const float& deltaTime);
	//Render
	void render(sf::RenderTarget* target);
};
#endif


