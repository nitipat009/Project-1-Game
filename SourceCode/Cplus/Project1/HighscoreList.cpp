#include "HighscoreList.h"

bool HighscoreList::sortScoreDesc(const sf::Vector2<int>& a, const sf::Vector2<int>& b)
{
	return (a.y > b.y);
}

HighscoreList::HighscoreList(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	tex_bg.loadFromFile("Useful/MENU/bg.png");
	m_bg.setTexture(tex_bg);
	font.loadFromFile("Useful/font/Maple/Maplestory Light.ttf");
	


	m_name.setCharacterSize(50);
	m_name.setFillColor(sf::Color::White);
	m_points.setCharacterSize(50);
	m_points.setFillColor(sf::Color::White);

	initHighscoreList();

	this->button["BACK"] = new Button(
		1920 / 1.5, 1080 / 4 * 3, 150, 50,
		&this->font, "BACK", 30,
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

}

HighscoreList::~HighscoreList()
{
}

void HighscoreList::initHighscoreList()
{
	//first open the file
	
	file.open("highscore.txt", std::ios::in);
	if (file.fail()) {
		perror("could not load highscore.txt file\n");
	}

	//create some stuff for temp save
	std::string tmpPoints,tmpName,tmpstr; ///< to display in game later
	int tmpNumPoints;

	//now extract the integer we need (points, shots fired, shots got, difficulty)
	while (file >> word) {

		//and store it into the integer
		//------------------------X--------------Y----------Z-------
		//m_numInput.emplace_back(tmpstr , tmpNumPoints);
		tmpstr = word.substr(0, word.find(','));
		std::cout << tmpstr << std::endl;
		tmpNumPoints = std::stoi(word.substr(word.find(',') + 1, word.length()));
		std::cout << tmpNumPoints << std::endl;
		stored[tmpNumPoints] = tmpstr;
	}

	//won't need file anymore
	file.close();
	end = stored.end();
	beg = stored.begin();
	end--;
	beg--;

}

void HighscoreList::update_btn()
{
	for (auto& it : this->button) {
		it.second->update(this->m_posview);
	}

	

	if (this->button["BACK"]->isPressed())
	{
		this->quit = true;

	}

}

void HighscoreList::update(const float& deltaTime)
{
	updateMousePOS();
	update_btn();
	

	

}

void HighscoreList::render_score(RenderTarget* target)
{
	
	sf::Text text("", font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	text.setString("Name");
	text.setPosition(1920 / 3, 450);
	target->draw(text);
	text.setString("Score");
	text.setPosition(1920 / 2, 450);
	target->draw(text);
	for (std::map<int, std::string>::iterator it = end; it != beg; it--) {
		text.setString(it->second);
		text.setPosition(1920/3, 530 + 80 * currentDisplay);
		target->draw(text);
		text.setString(std::to_string(it->first));
		text.setPosition(1920/2, 530 + 80 * currentDisplay);
		target->draw(text);
		currentDisplay++;
		if (currentDisplay == 5)
		{
			break;
		}
	}
	currentDisplay = 0;
	
}

void HighscoreList::render(RenderTarget* target)
{

	if (!target)
		target = this->window;


	target->draw(m_bg);
	render_score(target);
	for (auto& it : this->button) {
		it.second->render(target);
	}
	

}

void HighscoreList::endState()
{
}
