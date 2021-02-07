//HighscoreManager.cpp

#include "HighscoreManager.h"

HighscoreManager::HighscoreManager() {
	
	hPoints = 0;
	
}

//setter

void HighscoreManager::setName(std::string playername)
{
	
	hName = playername;
}

//sets the Points the player got to the highscore
void HighscoreManager::setPoints(int points) { //in game initialized
	hPoints = points;
}

