//HighscoreManager.h

#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include<string>

class HighscoreManager {
public:
	HighscoreManager();

	//setter
	void setName(std::string playername);
	void setPoints(int points);



	//getter

	//returns earned points
	std::string getName() const { return hName; };
	int getPoints() const { return hPoints; };
	

private:

	std::string hName;
	int hPoints;
	
};
#endif