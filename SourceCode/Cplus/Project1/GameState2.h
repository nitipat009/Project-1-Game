#ifndef GAMESTATE2_H
#define GAMESTATE2_H

#include "State.h"
#include "Menu.h"


class GameState2 :
	public State
{
private:
	//Variables
	//Menu *menu;


	sf::View view;
	sf::Clock clock;
	sf::Clock pClock;
	Clock spawn_time, spawn_time3;
	Clock e_cooldown;
	sf::Text Score;
	sf::Texture playerTex;
	//----------BULLET
	sf::Sprite bullet;
	sf::Texture tex, laser;
	sf::Sound sound_shoot;
	sf::SoundBuffer buffer_shoot;
	PauseMenu* pmenu;
	DeadMenu* dmenu;


	//-------POTION
	Potion* potion;
	std::vector<Potion> potions, potions2, potions3;
	sf::Texture potion_tex, potion_tex2, potion_tex3;
	std::vector<Bullet> bullets, range_;

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
	bool boss_spawn = false;
	bool boss_death = false;
	sf::Vector2u textureSize;
	sf::IntRect rect;



	//SOUND//

	sf::SoundBuffer buffer_back, buffer_hited, buffer_zomhit;
	sf::Sound sound;
	sf::Sound sound_hitted, sound_zomhit;

	//BACKGROUND//
	sf::Texture BackgroundTexture[2];
	sf::Texture bg_starTex, bg_moonTex, bg_cloudTex, bg_cloud1Tex, bg_cloud2Tex, bg_treeTex;
	sf::Sprite bg_star, bg_moon, bg_cloud, bg_cloud1, bg_cloud2, bg_tree;
	sf::Sprite background, background_d;
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.


	//------------------GROUND------------------------//
	sf::Texture ground_Texture;
	sf::Texture ground_upTex;
	sf::Sprite ground;






	std::vector<Platform> platforms;
	std::vector<Enenmy> enemies, enemies3, bosses1;

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

	void big_potion(sf::Vector2f position);
	void master_potion(sf::Vector2f position);
	void small_potion(sf::Vector2f position);

	void enemy_act(sf::Vector2f enemy);
	void map_update();
	void inithp();
	void initState();
	void initView();
	void updatePauseMenuButtons();

public:
	//Constructors/Destructors
	GameState2(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~GameState2();

	//Functions
	void Loader();

	void endState();


	//Update
	void update(const float& deltaTime);
	//Render
	void render(sf::RenderTarget* target);
};
#endif