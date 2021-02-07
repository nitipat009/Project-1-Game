#include "GameState.h"
#include"stdax.h"
#include"Menu.h"
void GameState::spawn(sf::Vector2f player)
{
	
	this->enemy = new Enenmy(&this->enemy_tex, sf::Vector2u(4, 1), 0.06f, 150.0f, sf::Vector2f(player.x+1400.0f, 900.0f),sf::Vector2f(100.0f,100.0f));
	//enemies.push_back(Enenmy(&this->enemy_tex, sf::Vector2u(16, 1), 0.06f, 150.0f, sf::Vector2f(800.0f, 870.0f)));
	if (spawn_time.getElapsedTime().asSeconds() >= 2.0f && stage == 1) {
		enemies.push_back(Enenmy(*this->enemy));
		spawn_time.restart();
	}
	

}
void GameState::spawn3(sf::Vector2f player)
{
	this->enemy = new Enenmy(&this->enemy_tex3, sf::Vector2u(6, 2), 0.06f, 150.0f, sf::Vector2f(player.x + 1400.0f, 400.0f), sf::Vector2f(100.0f, 100.0f));
	//enemies.push_back(Enenmy(&this->enemy_tex, sf::Vector2u(16, 1), 0.06f, 150.0f, sf::Vector2f(800.0f, 870.0f)));
	if (spawn_time3.getElapsedTime().asSeconds() >=	4.0f && boss2_death == false) {
		enemies3.push_back(Enenmy(*this->enemy));
		spawn_time3.restart();
	}

	if (player.x >= 6700) {
		if (spawn_time3.getElapsedTime().asSeconds() >= 2.0f) {
			enemies3.push_back(Enenmy(*this->enemy));
			spawn_time3.restart();
		}
	}
	
}
void GameState::boss1(sf::Vector2f player)
{
	this->enemy = new Enenmy(&this->boss_tex1, sf::Vector2u(5, 1), 0.06f, 150.0f, sf::Vector2f(7600.0f, 890.0f), sf::Vector2f(250.0f, 250.0f));
	//enemies.push_back(Enenmy(&this->enemy_tex, sf::Vector2u(16, 1), 0.06f, 150.0f, sf::Vector2f(800.0f, 870.0f)));
	if (player.x >= 6000 && boss_spawn == false) {
		bosses1.push_back(*this->enemy);
		boss_spawn = true;
		//spawn_time.restart();
	}

}
void GameState::boss2(sf::Vector2f player)
{
	this->enemy = new Enenmy(&this->boss_tex2, sf::Vector2u(4, 1), 0.06f, 150.0f, sf::Vector2f(14500.0f, 890.0f), sf::Vector2f(250.0f, 250.0f));
	//enemies.push_back(Enenmy(&this->enemy_tex, sf::Vector2u(16, 1), 0.06f, 150.0f, sf::Vector2f(800.0f, 870.0f)));
	if (player.x >= 13000 && boss2_spawn == false) {
		bosses2.push_back(*this->enemy);
		boss2_spawn = true;
		//spawn_time.restart();
	}

}
void GameState::big_potion(sf::Vector2f position)
{
	this->potion = new Potion(&this->potion_tex, sf::Vector2f(70.0f, 70.0f), Vector2f(position.x, position.y - 50), player->hp);

		
		potions.push_back(*this->potion);
	
	
}
void GameState::master_potion(sf::Vector2f position)
{
	this->potion = new Potion(&this->potion_tex2, sf::Vector2f(50.0f, 50.0f), Vector2f(position.x, position.y - 50), player->hp);

		
	potions2.push_back(*this->potion);
	
}
void GameState::small_potion(sf::Vector2f position)
{
	this->potion = new Potion(&this->potion_tex3, sf::Vector2f(50.0f, 50.0f), Vector2f(position.x, position.y - 50), player->hp);
	
		
	potions3.push_back(*this->potion);
	

}
void GameState::enemy_act()
{
	

	for (Enenmy& enemy : enemies3) {
		
		
		//std::cout << showtime << std::endl;
		enemy.Update(deltaTime);

		


		
		
		


				

				this->b.range.setTexture(&this->laser);
				if (e_cooldown.getElapsedTime().asSeconds() >= 2.0f) {


					range_.push_back(b);
					

				}


				enemy.enemyCenter = Vector2f(enemy.GetPosition().x,
					enemy.GetPosition().y);
				enemy.playerPos = this->player->GetPosition();

				enemy.aim = enemy.playerPos - enemy.enemyCenter;
				enemy.aim = enemy.aim / sqrt(pow(enemy.aim.x, 2) + pow(enemy.aim.y, 2));
				this->b.range.setPosition(enemy.enemyCenter);
				this->b.enemy_v = enemy.aim * 4.0f;



				for (size_t i = 0; i < range_.size(); i++)
				{
					range_[i].range.move(range_[i].enemy_v);


					if (range_[i].range.getPosition().x > this->window->getSize().x * 20 || range_[i].range.getPosition().y > this->window->getSize().y || range_[i].range.getPosition().x < 0 || range_[i].range.getPosition().y < 0)
					{
						range_.erase(range_.begin() + i);


					}



				}


				for (size_t i = 0; i < range_.size(); i++)
				{

					if (Collision::PixelPerfectTest(range_[i].range, player->body)) {
						range_.erase(range_.begin() + i);
						this->player->hp -= 5;
						sound_hitted.play();
						this->HP.setSize(sf::Vector2f(230.f * (float)this->player->hp / 100, 20));
					}
				}
				
			


		
		






	}
		


	

}
void GameState::boss_act(){
	for (Enenmy& enemy : bosses2) {
		enemy.Update(deltaTime);



		this->b.b_range.setTexture(&this->boss_laser);
		if (boss_c.getElapsedTime().asSeconds() >= 0.75f) {


			bosses_b.push_back(b);


		}


		enemy.bossCenter = Vector2f(enemy.GetPosition().x,
			enemy.GetPosition().y);
		enemy.playerPos = this->player->GetPosition();

		enemy.aim = enemy.playerPos - enemy.bossCenter;
		enemy.aim = enemy.aim / sqrt(pow(enemy.aim.x, 2) + pow(enemy.aim.y, 2));
		this->b.b_range.setPosition(enemy.bossCenter);
		this->b.boss_v = enemy.aim * 4.0f;



		for (size_t i = 0; i < bosses_b.size(); i++)
		{
			bosses_b[i].b_range.move(bosses_b[i].boss_v);


			if (bosses_b[i].b_range.getPosition().x > this->window->getSize().x * 20 || bosses_b[i].b_range.getPosition().y > this->window->getSize().y || bosses_b[i].b_range.getPosition().x < 0 || bosses_b[i].b_range.getPosition().y < 0)
			{
				bosses_b.erase(bosses_b.begin() + i);


			}



		}


		for (size_t i = 0; i < bosses_b.size(); i++)
		{

			if (Collision::PixelPerfectTest(bosses_b[i].b_range, player->body)) {
				bosses_b.erase(bosses_b.begin() + i);
				this->player->hp -= 5;
				
				sound_hitted.play();

				
				this->HP.setSize(sf::Vector2f(230.f * (float)this->player->hp / 100, 20));
			}
		}

	}

}
void GameState::inithp()
{
	this->HP = sf::RectangleShape(sf::Vector2f(250, 30));
}
void GameState::initState()
{
	//this->states.push(new GameState(this->window));
}
void GameState::initView()
{
	view = sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920, 1080));
}
void GameState::updatePauseMenuButtons()
{
	if (this->dmenu->isButtonPressed("CONTINUE"))
	{
		sound.stop();
		this->states->pop();
		this->states->push(new GameState(this->window, this->states,this->hName));
	}

	if (this->dmenu->isButtonPressed("EXIT_MENU"))
	{
		this->endState();
	}

	if (this->pmenu->isButtonPressed("EXIT_MENU"))
	{
		this->endState();
	}
}
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, std::string name)
	: State(window, states) 
{
	this->initState();
	this->initView();
	this->inithp();
	this->Loader();
	this->pmenu = new PauseMenu(*this->window, this->font);
	this->pmenu->addButton("EXIT_MENU",200.f,"EXIT");
	this->dmenu = new DeadMenu(*this->window, this->font);
	this->dmenu->addButton("EXIT_MENU", 200.f, "EXIT");
	this->dmenu->addButton("CONTINUE", 200.f, "CONTINUE");
	this->hName = name;
	//this->pmenu = new PauseMenu(window);
	this->player = new Player(&this->playerTex, sf::Vector2u(5, 3), 0.06f, 300.0f, 2000.0f);
	stage = 1;
	
	

	//GROUND
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(400.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(1200.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(2000.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(2800.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(3600.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(4400.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(5200.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(6000.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(6800.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_Texture, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(7600.0f, 1035.0f)));
	//platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343.0f, 93.0f), sf::Vector2f(1400.0f, 800.0f)));
	//platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343.0f, 93.0f), sf::Vector2f(2000.0f, 700.0f)));
	//platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343.0f, 93.0f), sf::Vector2f(5000.0f, 800.0f)));

	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(8400.0f, 800.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(9000.0f, 700.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(9600.0f, 900.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(10200.0f, 800.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(10800.0f, 1000.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(11400.0f, 900.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(12000.0f, 800.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(12600.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(13500.0f, 1035.0f)));
	//platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(15600.0f, 1035.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(13000.0f, 850.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(13900.0f, 850.0f)));
	//platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(13200.0f, 450.0f)));
	platforms.push_back(Platform(&ground_upTex, sf::Vector2f(343, 93), sf::Vector2f(13500.0f, 700.0f)));


	

}
GameState::~GameState()
{
	
	
	this->boss_spawn = false;
	view.setCenter(970, 550);
	this->window->setView(view);
}
void GameState::Loader()
{
	//---------------FONT-----------------//
	
	if (!font.loadFromFile("Useful/font/Maple/Maplestory Light.ttf")) {
		throw "ERROR FONT";

	}

	//---------------HPBAR-----------------//
	HPbar.loadFromFile("Useful/Health_Bar/Health.png");
	hpbar.setTexture(HPbar);
	sf::RectangleShape HP(sf::Vector2f(250, 30));
	this->HP.setFillColor(sf::Color::Red);
	this->HP.setSize(sf::Vector2f(230, 20));
	//---------------BULLET----------------//
	/*if (!tex.loadFromFile("Useful/Bullet/bullet.png"))
	{
		throw "Can't load bullet texture";
	}
	else
		b.shape.setTexture(&tex);*/
	Collision::CreateTextureAndBitmask(tex, "Useful/Bullet/bullet.png");
	Collision::CreateTextureAndBitmask(laser, "Useful/Bullet/laser.png");
	Collision::CreateTextureAndBitmask(boss_laser, "Useful/Bullet/test.png");

	//----------------SOUND----------------//
	if (!buffer_shoot.loadFromFile("Useful/Sounds/shooting.wav")) {
		throw "Error";
	}
	if (!buffer_back.loadFromFile("Useful/background.wav")) {
		throw "Error";
	}
	if (!buffer_zomhit.loadFromFile("Useful/Sounds/38[zomhit].ogg")) {
		throw "Error";
	}
	if (!buffer_hited.loadFromFile("Useful/Sounds/11 [Hited].ogg")) {
		throw "Error";
	}
	
	sound.setBuffer(buffer_back);
	sound_hitted.setBuffer(buffer_hited);
	sound_zomhit.setBuffer(buffer_zomhit);
	sound_shoot.setBuffer(buffer_shoot);
	sound_shoot.setRelativeToListener(true);
	sound_hitted.setRelativeToListener(true);
	sound.setLoop(true);
	
	sound.play();
	
	//----------------SOUND----------------//


	//------------------BG-----------------//
	if (!BackgroundTexture[0].loadFromFile("Useful/background/bgnew.png"))
	{

	}
	else
	{
		TextureSize = BackgroundTexture[0].getSize(); //Get size of texture

		WindowSize = this->window->getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.
		background.setScale(2.5, 2);
		background.setTexture(BackgroundTexture[0]);
		background.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
		BackgroundTexture[0].setRepeated(true);
		BackgroundTexture[0].setSmooth(false);
		background.setOrigin(960.f, 540.f);
		//background.setScale(ScaleX*5, ScaleY);      //Set scale.




	}

	if (!bg_vicTex.loadFromFile("Useful/background/victory.png"))
	{

	}
	else
	{
		TextureSize = bg_vicTex.getSize(); //Get size of texture

		WindowSize = this->window->getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.
		bg_vic.setScale(1, 1);
		bg_vic.setTexture(bg_vicTex);
		bg_vic.setOrigin(960, 540);
		//bg_vicTex.setRepeated(true);




	}

	bg_starTex.loadFromFile("Useful/background/bg_star.png");
	bg_star.setScale(2.5, 2);
	bg_star.setTexture(bg_starTex);
	bg_star.setOrigin(960,540);
	bg_starTex.setRepeated(true);

	bg_moonTex.loadFromFile("Useful/background/bg_moon.png");
	bg_moon.setScale(2.5, 2);
	bg_moon.setTexture(bg_moonTex);
	bg_moon.setOrigin(960, 540);
	bg_moonTex.setRepeated(true);


	bg_cloudTex.loadFromFile("Useful/background/bg_cloudnew.png");
	bg_cloud.setScale(2.5, 2);
	bg_cloud.setTexture(bg_cloudTex);
	bg_cloud.setOrigin(960, 540);
	bg_cloudTex.setRepeated(true);
	bg_cloudTex.setSmooth(true);


	bg_cloud1Tex.loadFromFile("Useful/background/bg_cloud1.png");
	bg_cloud1.setScale(2.5, 2);
	bg_cloud1.setTexture(bg_cloud1Tex);
	bg_cloud1.setOrigin(960, 540);
	bg_cloud1Tex.setRepeated(true);


	bg_cloud2Tex.loadFromFile("Useful/background/bg_cloud2.png");
	bg_cloud2.setScale(2.5, 2);
	bg_cloud2.setTexture(bg_cloud2Tex);
	bg_cloud2.setOrigin(960, 540);
	bg_cloud2Tex.setRepeated(true);

	bg_treeTex.loadFromFile("Useful/background/bg_tree.png");
	bg_tree.setScale(2, 2);
	bg_tree.setTexture(bg_treeTex);
	bg_tree.setOrigin(960, 540);
	bg_treeTex.setRepeated(true);


	
	//-----------------DEAD-----------------//
	if (!BackgroundTexture[1].loadFromFile("Useful/Dead Scene/hqdefault.jpg"))
	{

	}
	else
	{
		TextureSize = BackgroundTexture[1].getSize(); //Get size of texture

		WindowSize = this->window->getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.
		background_d.setScale(ScaleX, ScaleY);
		background_d.setOrigin(ScaleX / 2, ScaleY / 2);
		background_d.setTexture(BackgroundTexture[1], true);

		BackgroundTexture[1].setSmooth(true);
		//background.setScale(ScaleX*5, ScaleY);      //Set scale.




	}

	//----------------GROUND---------------//
	if (!ground_Texture.loadFromFile("Useful/Tile/ground.png"))
	{

	}
	else
	{

		/*ground.setTexture(ground_Texture);
		ground.setScale(800.0f,50.0f);
		ground.setTextureRect(sf::IntRect(0, 0, 4000, 50));
		ground_Texture.setRepeated(true);
		ground_Texture.setSmooth(true);

		ground.setPosition(ground_pos);*/
		ground_Texture.setRepeated(true);
	}
	if (!ground_upTex.loadFromFile("Useful/Tile/ground_up1.png"))
	{

	}
	else
	{

		/*ground.setTexture(ground_Texture);
		ground.setScale(800.0f,50.0f);
		ground.setTextureRect(sf::IntRect(0, 0, 4000, 50));
		ground_Texture.setRepeated(true);
		ground_Texture.setSmooth(true);

		ground.setPosition(ground_pos);*/
		ground_upTex.setRepeated(true);
	}


	//---------------COLLISION--------------//
	Collision::CreateTextureAndBitmask(enemy_tex, "Useful/enemy/enemy1/enemy1__.png");
	Collision::CreateTextureAndBitmask(enemy_tex3, "Useful/enemy/enemy3/enemy3_.png");
	Collision::CreateTextureAndBitmask(boss_tex1, "Useful/enemy/enemytest.png");
	Collision::CreateTextureAndBitmask(boss_tex2, "Useful/enemy/boss2.png");
	Collision::CreateTextureAndBitmask(playerTex, "Useful/shoot/shoot.png");

	Collision::CreateTextureAndBitmask(potion_tex, "Useful/Potion/Big_p.png");
	Collision::CreateTextureAndBitmask(potion_tex2, "Useful/Potion/masterious_p.png");
	Collision::CreateTextureAndBitmask(potion_tex3, "Useful/Potion/small_p.png");


}
void GameState::endState()
{
	this->quit = true;
	
}
void GameState::update(const float& deltaTime)
{
	this->updateMousePOS();
	this->check_pause();

	if (victory != true) {
		if (!this->died) {
			if (!this->paused) //Unpaused update
			{


				if (player->hp > 100) {
					player->hp = 100;
				}
				if (player->GetPosition().y >= 1080) {
					player->hp = 0;
				}
				this->spawn(this->player->GetPosition());
				this->spawn3(this->player->GetPosition());
				this->boss1(this->player->GetPosition());
				this->boss2(this->player->GetPosition());


				if (player->GetPosition().x >= 4000 && check == false) {
					if (potion->generateRandom(4) == 1) {

						if (potion->generateRandom(2) == 1) {

							master_potion(sf::Vector2f(5000, 800));
						}
						else
							small_potion(sf::Vector2f(5000, 800));

					}

					check = true;
				}
				for (Potion& potion : potions2) {
					if (Collision::PixelPerfectTest(player->body, this->potion->body)) {

						for (auto itr = std::begin(potions); itr != std::end(potions); ++itr)
						{
							if (potion.generateRandom(2) == 1) {
								score_point += 100;
							}
							else
								player->hp -= 50;

							potions2.erase(itr);
							break;
						}


					}
				}
				for (Potion& potion : potions3) {
					if (Collision::PixelPerfectTest(player->body, this->potion->body)) {

						for (auto itr = std::begin(potions); itr != std::end(potions); ++itr)
						{
							player->hp += 25;
							potions3.erase(itr);
							break;
						}

					}
				}
				for (Potion& potion : potions) {
					if (Collision::PixelPerfectTest(player->body, this->potion->body)) {

						this->player->hp = 100;
						this->HP.setSize(sf::Vector2f(230.f * (float)this->player->hp / 100, 20));
						for (auto itr = std::begin(potions); itr != std::end(potions); ++itr)
						{

							potions.erase(itr);
							break;
						}


					}


				}



				this->player->Update(deltaTime);
				if (this->player->hp <= 0 && !died) {
					died = true;
					this->player->hp = 0;
				}
				//this->enemy->Update(deltaTime);

				for (Enenmy& enemy : enemies) {
					enemy.Update(deltaTime);

				}


				this->enemy_act();

				for (Enenmy& enemy : bosses1) {
					enemy.Update(deltaTime);

				}
				this->boss_act();
				for (Potion& potion : potions) {
					potion.Update(deltaTime);

				}
				for (Potion& potion : potions2) {
					potion.Update(deltaTime);

				}
				for (Potion& potion : potions3) {
					potion.Update(deltaTime);

				}


				/*if (Keyboard::isKeyPressed(Keyboard::R) && b.bulletClip == 0) {
					b.bulletClip = 30;

				}*/


				if (Mouse::isButtonPressed(Mouse::Left))
				{

					if (canfire) {
						b.shape.setTexture(&this->tex);
						bullets.push_back(b);
						pClock.restart();
						canfire = false;
						b.bulletClip--;

						sound_shoot.play();





					}

				}
				else {

					/*sound_shoot.stop();
					sound_shoot.Stopped;*/
				}


				if (!canfire)
					if (pClock.getElapsedTime().asSeconds() >= b.mCooldown / stage)
						canfire = true;

				playerCenter = Vector2f(this->player->GetPosition().x + 20.0f,
					this->player->GetPosition().y - 20.0f);
				mousePos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*window));

				aimDir = mousePos - playerCenter;
				aimDir = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
				b.shape.setPosition(playerCenter);
				b.currVelocity = aimDir * b.maxSpeed;


				for (size_t i = 0; i < bullets.size(); i++)
				{
					bullets[i].shape.move(bullets[i].currVelocity);


					if (bullets[i].shape.getPosition().x > this->window->getSize().x * 20 || bullets[i].shape.getPosition().y > this->window->getSize().y || bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().y < 0)
					{
						bullets.erase(bullets.begin() + i);
					}

					/*if (Collision::PixelPerfectTest(bullets[i].shape, enemy.body)) {
						bullets.erase(bullets.begin() + i);
						enemy.health -= 10;
						std::cout << "Collider";


					}*/

				}








				//------------BULLET--------------------//

				sf::Vector2f direction;
				for (Platform& platform : platforms) {
					if (platform.GetCollider().CheckCollision(this->player->GetColision(), direction, 1.0f, false)) {
						this->player->Oncolision(direction);
					}
					for (Potion& potion : potions) {
						if (platform.GetCollider().CheckCollision(potion.GetColision(), direction, 1.0f, false)) {
							potion.Oncolision(direction);
						}
					}
					for (Potion& potion : potions2) {
						if (platform.GetCollider().CheckCollision(potion.GetColision(), direction, 1.0f, false)) {
							potion.Oncolision(direction);
						}
					}
					for (Potion& potion : potions3) {
						if (platform.GetCollider().CheckCollision(potion.GetColision(), direction, 1.0f, false)) {
							potion.Oncolision(direction);
						}
					}


				}









				//std::cout << player.GetPosition().y << std::endl;
				//VIEW//
				if (this->player->GetPosition().x < 0) {
					this->player->velocity.x = 0.0f;
					this->player->setPosition(0.0f, this->enemy->GetPosition().y);
				}
				if (this->player->GetPosition().x > 7600 && stage == 1) {
					this->player->velocity.x = 0.0f;
					this->player->setPosition(7600.0f, this->enemy->GetPosition().y);
				}
				if (this->player->GetPosition().x <= 6278 && stage == 1) {
					view.setCenter(this->player->GetPosition().x + 400, 550); // View player.GetPosition().y-220.f
					background_d.setPosition(view.getSize().x, 0);
					HP.setPosition(this->player->GetPosition().x - 540, 25);
					hpbar.setPosition(this->player->GetPosition().x - 560, 20);
					Score.setPosition(this->player->GetPosition().x + 250, 20);
				}

				if (this->player->GetPosition().x >= 570) {
					view.setCenter(this->player->GetPosition().x + 400, 550); // View player.GetPosition().y-220.f
					background_d.setPosition(view.getSize().x, 0);
					HP.setPosition(this->player->GetPosition().x - 540, 25);
					hpbar.setPosition(this->player->GetPosition().x - 560, 20);
					Score.setPosition(this->player->GetPosition().x + 250, 20);
				}
				else if (this->player->GetPosition().x > 6287 && stage == 1) {
					view.setCenter(6287 + 400, 550); // View player.GetPosition().y-220.f
					background_d.setPosition(view.getSize().x, 0);
					HP.setPosition(6287 - 540, 25);
					hpbar.setPosition(6287 - 560, 20);
					Score.setPosition(6287 + 250, 20);

				}
				else if (this->player->GetPosition().x < 570) {
					view.setCenter(570 + 400, 550); // View player.GetPosition().y-220.f
					background_d.setPosition(view.getSize().x, 0);
					HP.setPosition(570 - 540, 25);
					hpbar.setPosition(570 - 560, 20);
					Score.setPosition(570 + 250, 20);
				}



				//------------ENEMY MOVEMENT
				for (Enenmy& enemy : enemies) {

					if (enemy.GetPosition().x > this->player->GetPosition().x)
					{
						enemy.velocity.x = -1.f;


						if (enemy.GetPosition().x > 7600) {
							enemy.velocity.x = 0.0f;
							enemy.setPosition(7600.0f, this->enemy->GetPosition().y);
						}

					}
					if (enemy.GetPosition().x < this->player->GetPosition().x)
					{
						enemy.velocity.x = 1.f;
						if (enemy.GetPosition().x < 0) {
							enemy.velocity.x = 0.0f;
							enemy.setPosition(0.0f, this->enemy->GetPosition().y);
						}


					}

					/*if (enemy.GetPosition().y > this->player->GetPosition().y)
					{
						enemy.velocity.y -= 0.025f;




					}
					if (enemy.GetPosition().y < this->player->GetPosition().y)
					{
						enemy.velocity.y += 0.025f;


					}*/

					if (!Collision::PixelPerfectTest(this->player->body, enemy.body)) {
						colider[0] = false;

					}
					if (Collision::PixelPerfectTest(this->player->body, enemy.body) && colider[0] == false) {
						colider[0] = true;
						enemy.velocity.x = 0;


						if (sound_hitted.getStatus() != 2) {
							sound_hitted.play();

						}

						if (sound_zomhit.getStatus() != 2) {
							sound_zomhit.play();
						}

						this->player->hp -= 1;
						this->HP.setSize(sf::Vector2f(230.f * (float)this->player->hp / 100, 20));



					}

					for (size_t i = 0; i < bullets.size(); i++)
					{
						if (bullets[i].shape.getGlobalBounds().intersects(enemy.body.getGlobalBounds()))
						{
							bullets.erase(bullets.begin() + i);
							enemy.health -= 50;
						}
					}


					//KILL
					for (auto itr = std::begin(enemies); itr != std::end(enemies); ++itr)
					{
						if (itr->health <= 0) {
							enemies.erase(itr);
							score_point += 10;
							break;
						}
					}

				}
				for (Enenmy& enemy : enemies3) {

					if (enemy.GetPosition().x > this->player->GetPosition().x)
					{
						enemy.velocity.x = -2.f;


						/*if (enemy.GetPosition().x > 7600) {
							enemy.velocity.x = 0.0f;
							enemy.setPosition(7600.0f, 400);
						}*/

					}
					else if (enemy.GetPosition().x < this->player->GetPosition().x)
					{
						enemy.velocity.x = 2.f;
						if (enemy.GetPosition().x < 0) {
							enemy.velocity.x = 0.0f;
							enemy.setPosition(0.0f, 400);
						}


					}


					if (stage == 2) {
						if (enemy.GetPosition().y > this->player->GetPosition().y)
						{
							enemy.velocity.y = -2.f;




						}
						else if (enemy.GetPosition().y < this->player->GetPosition().y)
						{
							enemy.velocity.y = 2.f;



						}
					}



					if (Collision::PixelPerfectTest(this->player->body, enemy.body) && colider[1] == false) {
						colider[1] = true;
						enemy.velocity.x = 0;


						if (sound_hitted.getStatus() != 2) {
							sound_hitted.play();

						}

						if (sound_zomhit.getStatus() != 2) {
							sound_zomhit.play();
						}

						this->player->hp -= 1;
						this->HP.setSize(sf::Vector2f(230.f * (float)this->player->hp / 100, 20));

					}
					if (!Collision::PixelPerfectTest(this->player->body, enemy.body)) {
						colider[1] = false;

					}
					for (size_t i = 0; i < bullets.size(); i++)
					{
						if (bullets[i].shape.getGlobalBounds().intersects(enemy.body.getGlobalBounds()))
						{
							bullets.erase(bullets.begin() + i);
							enemy.health -= 50;
						}
					}


					for (auto itr = std::begin(enemies3); itr != std::end(enemies3); ++itr)
					{
						if (itr->health <= 0) {

							enemies3.erase(itr);
							score_point += 10;
							break;
						}
					}


				}
				for (Enenmy& enemy : bosses1) {

					if (enemy.GetPosition().x > this->player->GetPosition().x)
					{
						enemy.velocity.x = -4.f;


						if (enemy.GetPosition().x > 7600) {
							enemy.velocity.x = 0.0f;
							enemy.setPosition(7600.0f, this->enemy->GetPosition().y);
						}

					}
					if (enemy.GetPosition().x < this->player->GetPosition().x)
					{
						enemy.velocity.x = 4.f;
						if (enemy.GetPosition().x < 0) {
							enemy.velocity.x = 0.0f;
							enemy.setPosition(0.0f, this->enemy->GetPosition().y);
						}


					}
					if (player->GetPosition().x >= 7600) {
						if (enemy.GetPosition().y > this->player->GetPosition().y)
						{
							enemy.velocity.y -= 0.025f;




						}
						if (enemy.GetPosition().y < this->player->GetPosition().y)
						{
							enemy.velocity.y += 0.025f;


						}
					}

					if (!Collision::PixelPerfectTest(this->player->body, enemy.body)) {
						colider[2] = false;

					}

					if (Collision::PixelPerfectTest(this->player->body, enemy.body) && colider[2] == false) {
						colider[2] = true;
						enemy.velocity.x = 0;


						if (sound_hitted.getStatus() != 2) {
							sound_hitted.play();

						}

						if (sound_zomhit.getStatus() != 2) {
							sound_zomhit.play();
						}

						this->player->hp -= 1;
						this->HP.setSize(sf::Vector2f(230.f * (float)this->player->hp / 100, 20));



					}

					for (size_t i = 0; i < bullets.size(); i++)
					{
						if (bullets[i].shape.getGlobalBounds().intersects(enemy.body.getGlobalBounds()))
						{
							bullets.erase(bullets.begin() + i);
							enemy.health -= 5;
						}
					}


					for (auto itr = std::begin(bosses1); itr != std::end(bosses1); ++itr)
					{
						if (itr->health <= 0) {
							bosses1.erase(itr);
							boss_death = true;
							score_point += 100;
							this->big_potion(sf::Vector2f(6800, enemy.GetPosition().y));
							change_map.restart();
							break;
						}
					}

				}
				for (Enenmy& enemy : bosses2) {

					if (enemy.GetPosition().y >= 890.0f) {
						direct = false;

					}
					if (enemy.GetPosition().y < 0.0f) {
						direct = true;
					}
					if (direct == false) {
						enemy.velocity.y = -5.0f;

					}
					else if (direct == true)
						enemy.velocity.y = 5.0f;


					if (!Collision::PixelPerfectTest(this->player->body, enemy.body)) {
						colider[2] = false;

					}

					if (Collision::PixelPerfectTest(this->player->body, enemy.body) && colider[2] == false) {
						colider[2] = true;
						enemy.velocity.x = 0;


						if (sound_hitted.getStatus() != 2) {
							sound_hitted.play();

						}

						if (sound_zomhit.getStatus() != 2) {
							sound_zomhit.play();
						}

						this->player->hp -= 1;
						this->HP.setSize(sf::Vector2f(230.f * (float)this->player->hp / 100, 20));



					}

					for (size_t i = 0; i < bullets.size(); i++)
					{
						if (bullets[i].shape.getGlobalBounds().intersects(enemy.body.getGlobalBounds()))
						{
							bullets.erase(bullets.begin() + i);
							enemy.health -= 5;
						}
					}


					for (auto itr = std::begin(bosses2); itr != std::end(bosses2); ++itr)
					{
						if (itr->health <= 0) {
							bosses2.erase(itr);
							boss2_death = true;
							score_point += 200;
							this->big_potion(sf::Vector2f(enemy.GetPosition().x, 800));
							change_map.restart();
							break;
						}
					}
				}

				if (boss_death == true) {

					enemies.clear();
					enemies3.clear();
					stage++;
					boss_death = false;

				}
				if (boss2_death == true) {

					enemies.clear();
					enemies3.clear();
					stage++;
					victory = true;


				}


				this->map_update();

				if (e_cooldown.getElapsedTime().asSeconds() >= 2.0f) {
					e_cooldown.restart();
				}
				if (boss_c.getElapsedTime().asSeconds() >= 0.75f) {
					boss_c.restart();
				}


			}
			else //Paused update
			{
				this->pmenu->update(view.getCenter(), this->m_posview);
				this->updatePauseMenuButtons();
			}
		}
		else {
			this->dmenu->update(view.getCenter(), this->m_posview, victory);
			if (highscoreWritten == false) {
				highscoreWritten = true;
				highscore.setName(hName);
				highscore.setPoints(score_point);
				iohighscore.WriteHighscore(highscore);
			}

			this->updatePauseMenuButtons();


		}
	}else{
		this->dmenu->update(view.getCenter(), this->m_posview, victory);
		if (highscoreWritten == false) {
		highscoreWritten = true;
		highscore.setName(hName);
		highscore.setPoints(score_point);
		iohighscore.WriteHighscore(highscore);
		}
		this->updatePauseMenuButtons();
		
		
	}
	

				


}
void GameState::map_update()
{
	background.setPosition(player->GetPosition().x,1080);
	bg_star.setPosition(player->GetPosition().x, 1080);
	bg_moon.setPosition(player->GetPosition().x, 600);
	bg_tree.setPosition(player->GetPosition().x, 1230);
	bg_cloud.setPosition(player->GetPosition().x, 1280);
	bg_cloud1.setPosition(player->GetPosition().x, 1080);
	bg_cloud2.setPosition(player->GetPosition().x, 1080);
	bg_vic.setPosition(player->GetPosition().x, 400);



	
	background.setTextureRect(IntRect(view.getCenter().x * 0.2, 0, 1920, 1080));
	bg_star.setTextureRect(IntRect(view.getCenter().x * 0.2, 0, 1920, 1080));
	//bg_moon.setTextureRect(IntRect(view.getCenter().x * 0.2, 0, 1920, 1080));
	bg_tree.setTextureRect(IntRect(view.getCenter().x*0.2, 0, 1920, 960));
	bg_cloud.setTextureRect(IntRect(view.getCenter().x * 0.2, 0, 1920, 1080));
	bg_cloud1.setTextureRect(IntRect(view.getCenter().x * 0.2, 0, 1920, 1080));
	bg_cloud2.setTextureRect(IntRect(view.getCenter().x * 0.2, 0, 1920, 1080));
	//bg_vic.setTextureRect(IntRect(view.getCenter().x * 0.2, 0, 1920, 1080));

}
void GameState::render(sf::RenderTarget* target)
{

		if (!target)
		target = this->window;

	
		target->draw(background);
		target->draw(bg_star);
		//target->draw(bg_moon);
		target->draw(bg_cloud);
		target->draw(bg_tree);

		target->draw(HP);
		player_gui(window, player, score_point);
		for (Platform& platform : platforms)
			platform.Draw(this->window);
		target->draw(hpbar);
		

		for (size_t i = 0; i < bullets.size(); i++)
		{

			this->window->draw(bullets[i].shape);


		}


		for (Enenmy& enemy : enemies) {
			enemy.Draw(this->window);

		}
		for (Enenmy& enemy : enemies3) {
			enemy.Draw(this->window);

			for (size_t i = 0; i < range_.size(); i++)
			{
				this->window->draw(range_[i].range);

			}

			
		}
		for (Enenmy& enemy : bosses1) {
			enemy.Draw(this->window);
		}
		for (Enenmy& enemy : bosses2) {
			enemy.Draw(this->window);
			for (size_t i = 0; i < bosses_b.size(); i++)
			{
				this->window->draw(bosses_b[i].b_range);

			}
		}
		for (Potion& potion : potions) {
			potion.Draw(this->window);
		}
		for (Potion& potion : potions2) {
			potion.Draw(this->window);
		}
		for (Potion& potion : potions3) {
			potion.Draw(this->window);
		}

		this->player->Draw(this->window);
		//this->enemy->Draw(this->window);
		if (boss_death ==true && player->GetPosition().x <= 7600) {
			target->draw(bg_vic);
		}
		


		//this->mouse_cursor(window);
		this->window->setView(view);

		if (this->paused) {
			
			this->pmenu->render(target);
			
		}

		if (this->died) {
			this->dmenu->render(target);
		}
		if (victory == true) {
			this->dmenu->render(target);
		}

	}
void GameState::Resize_View(const sf::RenderWindow& window, sf::View& view)
{

	/*float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(View_Width * aspectRatio, View_Height);
	view.setSize(float(window.getSize().x), float(window.getSize().y));*/

	//first we check our new aspect width to see if it changed
	float newAspectWidth = window.getSize().x;
	float newAspectHeight = window.getSize().y;
	if (newAspectWidth != View_Width)
	{
		//width changed, maintain the aspect ratio and adjust the height
		View_Width = newAspectWidth;
		View_Height = View_Width / aspectRatio;
	}
	else if (newAspectHeight != View_Height)
	{
		//height changed, maintain aspect ratio and change the width
		View_Height = newAspectHeight;
		View_Width = View_Height * aspectRatio;
	}
	std::cout << "width: " << View_Width << " height: " << View_Height << std::endl;
	view.setSize(newAspectWidth, newAspectHeight);


}
void GameState::mouse_cursor(sf::RenderWindow* window)
{

	sf::Vector2f mouse_pos;
	std::stringstream pos;

	sf::Font font;
	if (!font.loadFromFile("Useful/font/Madame.ttf")) {
		throw "ERROR FONT";

	}



	sf::Text mouse_postext;
	mouse_postext.setCharacterSize(15);
	mouse_postext.setFillColor(sf::Color::Red);
	mouse_postext.setFont(font);

	mouse_pos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	mouse_postext.setPosition(mouse_pos.x, mouse_pos.y + 20);
	pos << mouse_pos.x << "," << mouse_pos.y ;
	mouse_postext.setString(pos.str());

	window->draw(mouse_postext);

}
void GameState::player_gui(sf::RenderWindow* window, Player* player, int score_point)
{

	sf::Vector2f mouse_pos;
	std::stringstream pos;

	


	Score.setCharacterSize(30);
	Score.setFillColor(sf::Color::Red);
	Score.setFont(font);

	pos << "SCORE : " << score_point;
	Score.setString(pos.str());

	window->draw(Score);

}

