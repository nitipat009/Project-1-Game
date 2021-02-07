#include"stdax.h"

using namespace sf;



bool isWalk = false;

sf::Text Score;

static float View_Height = 1080,View_Width = 1920;

const float aspectRatio = 1.78;

void Resize_View(const sf::RenderWindow& window, sf::View& view);

void mouse_cursor(sf::RenderWindow *window);

void player_gui(sf::RenderWindow* window, Player* player, int score_point);
bool colider;
bool canfire = true;




int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mee Game!", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(View_Width, View_Height));

	
	int score_point = 0;

	//---------HEALTH BAR-------------//
	sf::Texture HPbar;
	
	if (!HPbar.loadFromFile("Useful/Health_Bar/Health.png"))

	{

		return EXIT_FAILURE;

	}

	sf::Sprite hpbar;


	int MyHP = 0;
	hpbar.setTexture(HPbar);
	sf::RectangleShape HP(sf::Vector2f(250, 30));

	

	HP.setFillColor(sf::Color::Red);

	HP.setSize(sf::Vector2f(230, 20));
	

	//---------HEALTH BAR-------------//

	
	sf::Sprite bullet;
	sf::Texture tex;
	sf::Sound sound_shoot;
	sf::SoundBuffer buffer_shoot;


	std::vector<Bullet> bullets;

	Vector2f playerCenter, mousePos, aimDir;
	//----------BULLET------------------//
	Bullet b;
	if (!tex.loadFromFile("Useful/Bullet/bullet.png"))
	{
		throw "Can't load bullet texture";
	}

		b.shape.setTexture(&tex);

	if (!buffer_shoot.loadFromFile("Useful/Sounds/machine-gun-01.wav")) {
		throw "Error";
	}

	sound_shoot.setBuffer(buffer_shoot);
	
	
	//sf::RectangleShape block(sf::Vector2f(50.f,50.f));
	


	sf::Texture enemy_tex;
	sf::Texture playerTex;
	sf::Vector2u textureSize;
	sf::IntRect rect;

	//SOUND//

	sf::SoundBuffer buffer_back, buffer_hited,buffer_zomhit;
	if (!buffer_back.loadFromFile("Useful/background.wav")) {
		throw "Error";
	}
	if (!buffer_zomhit.loadFromFile("Useful/Sounds/38[zomhit].ogg")) {
		throw "Error";
	}
	 
	
	
	if (!buffer_hited.loadFromFile("Useful/Sounds/11 [Hited].ogg")) {
		throw "Error";
	}
		
     

	sf::Sound sound;
	sf::Sound sound_hitted,sound_zomhit;

	sound.setBuffer(buffer_back);
	sound_hitted.setBuffer(buffer_hited);
	
	sound_zomhit.setBuffer(buffer_zomhit);

	sound.setLoop(true);
	sound.setVolume(5.f);
	sound.play();

	//BACKGROUND//
	sf::Texture BackgroundTexture[2];
	sf::Sprite background,background_d;
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.

	if (!BackgroundTexture[0].loadFromFile("Useful/map_.png"))
	{
		return -1;
	}
	else
	{
		TextureSize = BackgroundTexture[0].getSize(); //Get size of texture

		WindowSize = window.getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.
		background.setScale(ScaleX, ScaleY);
		background.setTexture(BackgroundTexture[0]);
		background.setTextureRect(sf::IntRect(0, 0, 4000, 1080));
		BackgroundTexture[0].setRepeated(true);
		BackgroundTexture[0].setSmooth(true);
		//background.setScale(ScaleX*5, ScaleY);      //Set scale.




	}

	if (!BackgroundTexture[1].loadFromFile("Useful/Dead Scene/hqdefault.jpg"))
	{
		return -1;
	}
	else
	{
		TextureSize = BackgroundTexture[1].getSize(); //Get size of texture

		WindowSize = window.getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.
		background_d.setScale(ScaleX, ScaleY);
		background_d.setOrigin(ScaleX/2, ScaleY/2);
		background_d.setTexture(BackgroundTexture[1],true);
		
		BackgroundTexture[1].setSmooth(true);
		//background.setScale(ScaleX*5, ScaleY);      //Set scale.




	}

	//---------------ENEMY----------------------------//
	//enemy_tex.loadFromFile("Useful/enemy/enemy.png");
	Collision::CreateTextureAndBitmask(enemy_tex, "Useful/enemy/enemy.png");
	//Enenmy enemy(&enemy_tex,sf::Vector2u(16,1), 0.15f, 150.0f,sf::Vector2f(400.0f,500.0f));




	//---------------ENEMY----------------------------//

	//------------------GROUND------------------------//
	sf::Texture ground_Texture;
	sf::Sprite ground;
	sf::Vector2f ground_pos(0.0f, 520.0f);

	if (!ground_Texture.loadFromFile("Useful/Tile/ground.png"))
	{
		return -1;
	}
	else
	{

		/*ground.setTexture(ground_Texture);
		ground.setScale(800.0f,50.0f);
		ground.setTextureRect(sf::IntRect(0, 0, 4000, 50));
		ground_Texture.setRepeated(true);
		ground_Texture.setSmooth(true);

		ground.setPosition(ground_pos);*/

	}


	//Setting Character
	//playerTex.loadFromFile("Useful/shoot/shoot.png");
	Collision::CreateTextureAndBitmask(playerTex, "Useful/shoot/shoot_LR.png");
	ground_Texture.setRepeated(true);
	//ground_Texture.setSmooth(true);

	std::vector<Platform> platforms;
	
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
	//--------Enemy------------//






	Player player(&playerTex, sf::Vector2u(6, 6), 0.15f, 300.0f, 1600.0f);
	



	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Clock pClock;
	
	//window.setFramerateLimit(60);





	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0 / 20) {
			deltaTime = 1.0 / 20;
		}

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				//Resize_View(window, view);
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
				break;




			}


		}

		


		player.Update(deltaTime);
		//enemy.Update(deltaTime);

		if (Keyboard::isKeyPressed(Keyboard::R) && b.bulletClip == 0) {
			b.bulletClip = 30;

		}
		

		if (Mouse::isButtonPressed(Mouse::Left) )
		{
			
			if (canfire) {
				
				bullets.push_back(Bullet(b));
				pClock.restart();
				canfire = false;

			}
			
			
			







			if (sound_shoot.getStatus() != 2) {
				sound_shoot.play();
				sound_shoot.Playing;
			}



		}
		else {
			if (sound_shoot.getStatus() == 2) {
				sound_shoot.stop();
				sound_shoot.Stopped;
			}
		}

		if (!canfire)
				if (pClock.getElapsedTime().asSeconds() >= b.mCooldown)
					canfire = true;

		playerCenter = Vector2f(player.GetPosition().x + 20.0f,
			player.GetPosition().y - 20.0f);
		mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

		aimDir = mousePos - playerCenter;
		aimDir = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
		b.shape.setPosition(playerCenter);
		b.currVelocity = aimDir * b.maxSpeed;



		




		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].shape.move(bullets[i].currVelocity);


			if (bullets[i].shape.getPosition().x > window.getSize().x * 5 || bullets[i].shape.getPosition().y > window.getSize().y || bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().y < 0)
			{
				bullets.erase(bullets.begin() + i);
			}
			/*if (bullets[i].shape.getGlobalBounds().intersects(enemy.body.getGlobalBounds()))
			{
				bullets.erase(bullets.begin() + i);
				score_point += 50;
			}*/

		}


		//------------BULLET--------------------//

		sf::Vector2f direction;
		for (Platform& platform : platforms) {
			if (platform.GetCollider().CheckCollision(player.GetColision(), direction, 1.0f)) {
				player.Oncolision(direction);
			}
			/*if (platform.GetCollider().CheckCollision(enemy.GetColision(), direction, 1.0f)) {
				enemy.Oncolision(direction);
			}*/


		}
		
			

		





			//std::cout << player.GetPosition().y << std::endl;

			//VIEW//
			if ( player.GetPosition().x >= 570) {
				view.setCenter(player.GetPosition().x+400, 550); // View player.GetPosition().y-220.f
				background_d.setPosition(view.getSize().x, 0);
				HP.setPosition(player.GetPosition().x - 540, 25);
				hpbar.setPosition(player.GetPosition().x -560, 20);
				Score.setPosition(player.GetPosition().x + 250, 20);
			}
			/*if (sound_zomhit.getStatus() == 2) {
				sound_zomhit.pause();
				sound_zomhit.Paused;
			}*/




			/*if (Collision::PixelPerfectTest(player.body, enemy.body) && colider == false) {
				colider = true;
				MyHP += 1;

				if (sound_hitted.getStatus() != 2) {
					sound_hitted.play();

				}

				/*if (sound_zomhit.getStatus() != 2) {
					sound_zomhit.play();

				}*/


			/*
					HP.setSize(sf::Vector2f(230.0f - (23.0f * MyHP), 20.0f));
					if (MyHP == 10) {
						window.clear();
						window.draw(background_d);
						window.display();

						system("pause");

					}

				}
				if (!Collision::PixelPerfectTest(player.body, enemy.body)) {
					colider = false;

				}*/



			
			/*if (player.body.getGlobalBounds().intersects(enemy.body.getGlobalBounds()) && colider == false) {
				colider = true;
				MyHP += 1;

				if (sound_hitted.getStatus() != 2) {
					sound_hitted.play();

				}
				
				/*if (sound_zomhit.getStatus() != 2) {
					sound_zomhit.play();
					
				}*/

				
				
			/*	HP.setSize(sf::Vector2f(230.0f - (23.0f * MyHP), 20.0f));
				if (MyHP == 10) {
					window.clear();
					window.draw(background_d);
					window.display();

					system("pause");
					
				}

			}
			if (!player.body.getGlobalBounds().intersects(enemy.body.getGlobalBounds())) {
				colider = false;
				
			}*/

			
				

			//------------ENEMY
			/*if (enemy.GetPosition().x > player.GetPosition().x)
			{
				enemy.velocity.x -= 0.01f;

				
				if (enemy.GetPosition().x > 4000) {
					enemy.velocity.x -= 0.0f;
					enemy.setPosition(4000.0f, enemy.GetPosition().y);
				}

			}
			if (enemy.GetPosition().x < player.GetPosition().x)
			{
				enemy.velocity.x += 0.01f;
				if (enemy.GetPosition().x < 0) {
					enemy.velocity.x -= 0.0f;
					enemy.setPosition(0.0f, enemy.GetPosition().y);
				}
				

			}*/
			


			
			//sound_shoot.setRelativeToListener(true);
			/*if (Mouse::isButtonPressed(Mouse::Left) == false)
			{
				sound_shoot.pause();
				sound_shoot.Paused;


			}*/
			
			
			//------------BULLET--------------------//

			

			/*if (sound.getStatus() != 2) {
				sound.play();
				sound.Playing;
			}
			if (block.getGlobalBounds().intersects(player.GetRect())) {
				sound.pause();
				sound.Paused;


				if (sound_hitted.getStatus() != 2) {
					sound_hitted.play();
					sound.Playing;
				}
				player.setPosition(400, 520);
			}*/








			window.clear();
			
			window.draw(background);
			
			mouse_cursor(&window);
			
			window.draw(HP);
			player_gui(&window,&player,score_point);
			for (Platform& platform : platforms)
				platform.Draw(window);
			window.draw(hpbar);
			//enemy.Draw(window);
			for (size_t i = 0; i < bullets.size(); i++)
			{
				window.draw(bullets[i].shape);

			}
			player.Draw(window);
			
			window.setView(view);
			window.display();


			



		}

		return 0;
}


void Resize_View(const sf::RenderWindow& window, sf::View& view) {

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
	std::cout << "width: " << View_Width << " height: " << View_Height <<std::endl;
	view.setSize(newAspectWidth, newAspectHeight);
	

	
}

void mouse_cursor(sf::RenderWindow* window)
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
	pos << mouse_pos.x << "," << mouse_pos.y;
	mouse_postext.setString(pos.str());

	window->draw(mouse_postext);

}

void player_gui(sf::RenderWindow* window,Player *player,int score_point)
{
	sf::Vector2f mouse_pos;
	std::stringstream pos;

	sf::Font font;
	if (!font.loadFromFile("Useful/font/Madame.ttf")) {
		throw "ERROR FONT";

	}
	
	
	Score.setCharacterSize(30);
	Score.setFillColor(sf::Color::Red);
	Score.setFont(font);
	
	pos << "SCORE : " << score_point;
	Score.setString(pos.str());
	
	window->draw(Score);
}

