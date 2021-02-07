#include"stdax.h"
#include "Game.h"






void Game::inithp()
{
	this->HP =  sf::RectangleShape(sf::Vector2f(250, 30));
}

void Game::initState()
{
	//this->states.push(new GameState(this->window));
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(View_Width, View_Height), "Mee Game!", sf::Style::Close | sf::Style::Resize);
}

void Game::initView()
{
	view =  sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920, 1080));
}

Game::Game()// : player(&this->playerTex, sf::Vector2u(6, 6), 0.15f, 300.0f, 1600.0f), b(0.5f)
{
	this->initWindow();
	this->initState();
	this->initView();
	this->inithp();
	this->Loader();
	this->player = new Player(&this->playerTex, sf::Vector2u(6, 6), 0.15f, 300.0f, 1600.0f);
	
	
	
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


}

Game::~Game()
{
	delete	this->window;
	delete	this->player;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();

	}

}

void Game::Loader()
{


	//---------------HPBAR-----------------//
	HPbar.loadFromFile("Useful/Health_Bar/Health.png");
	hpbar.setTexture(HPbar);
	sf::RectangleShape HP(sf::Vector2f(250, 30));
	this->HP.setFillColor(sf::Color::Red);
	this->HP.setSize(sf::Vector2f(230, 20));
	//---------------BULLET----------------//
	if (!tex.loadFromFile("Useful/Bullet/bullet.png"))
	{
		throw "Can't load bullet texture";
	}else
		b.shape.setTexture(&tex);

	//----------------SOUND----------------//
	if (!buffer_shoot.loadFromFile("Useful/Sounds/machine-gun-01.wav")) {
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
	sound.setLoop(true);
	sound.setVolume(5.f);
	sound.play();
	//----------------SOUND----------------//


	//------------------BG-----------------//
	if (!BackgroundTexture[0].loadFromFile("Useful/map_.png"))
	{

	}
	else
	{
		TextureSize = BackgroundTexture[0].getSize(); //Get size of texture

		WindowSize = this->window->getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.
		background.setScale(ScaleX, ScaleY);
		background.setTexture(BackgroundTexture[0]);
		background.setTextureRect(sf::IntRect(0, 0, 4000, 1080));
		BackgroundTexture[0].setRepeated(true);
		BackgroundTexture[0].setSmooth(true);
		//background.setScale(ScaleX*5, ScaleY);      //Set scale.




	}
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


	//---------------COLLISION--------------//
	Collision::CreateTextureAndBitmask(enemy_tex, "Useful/enemy/enemy.png");
	Collision::CreateTextureAndBitmask(playerTex, "Useful/shoot/shoot_LR.png");
	

}

void Game::endApplication()
{
}

void Game::updateDt()
{
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0 / 20) {
		deltaTime = 1.0 / 20;
	}
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		switch (sfEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::Resized:
			//Resize_View(window, view);
			sf::FloatRect visibleArea(0, 0, sfEvent.size.width, sfEvent.size.height);
			this->window->setView(sf::View(visibleArea));
			break;
		}
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}


}

void Game::update()
{
	

	this->updateSFMLEvents();
	//if(!this->states.empty())
	//this->states.top()->update(this->deltaTime);


	this->player->Update(deltaTime);
	//enemy.Update(deltaTime);

	if (Keyboard::isKeyPressed(Keyboard::R) && b.bulletClip == 0) {
		b.bulletClip = 30;

	}


	if (Mouse::isButtonPressed(Mouse::Left))
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


		if (bullets[i].shape.getPosition().x > this->window->getSize().x * 5 || bullets[i].shape.getPosition().y > this->window->getSize().y || bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().y < 0)
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
		if (platform.GetCollider().CheckCollision(this->player->GetColision(), direction, 1.0f)) {
			this->player->Oncolision(direction);
		}
		/*if (platform.GetCollider().CheckCollision(enemy.GetColision(), direction, 1.0f)) {
			enemy.Oncolision(direction);
		}*/


	}









	//std::cout << player.GetPosition().y << std::endl;

	//VIEW//
	if (this->player->GetPosition().x >= 570) {
		view.setCenter(this->player->GetPosition().x + 400, 550); // View player.GetPosition().y-220.f
		background_d.setPosition(view.getSize().x, 0);
		HP.setPosition(this->player->GetPosition().x - 540, 25);
		hpbar.setPosition(this->player->GetPosition().x - 560, 20);
		Score.setPosition(this->player->GetPosition().x + 250, 20);
	}

}

void Game::render()
{

	this->window->clear();

	//if(!this->states.empty())
	//this->states.top()->render(this->window);

	this->window->draw(background);

	//this->mouse_cursor(window);

	this->window->draw(HP);
	player_gui(window, player, score_point);
	for (Platform& platform : platforms)
		platform.Draw(this->window);
	this->window->draw(hpbar);
	//enemy.Draw(window);
	for (size_t i = 0; i < bullets.size(); i++)
	{
		this->window->draw(bullets[i].shape);

	}
	this->player->Draw(this->window);

	this->window->setView(view);
	this->window->display();
}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}

}



void Game::Resize_View(const sf::RenderWindow& window, sf::View& view)
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

void Game::mouse_cursor(sf::RenderWindow* window)
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

void Game::player_gui(sf::RenderWindow* window, Player* player, int score_point)
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