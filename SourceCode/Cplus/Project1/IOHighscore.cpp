#include "IOHighscore.h"


void IOHighscore::openWrite()
{
	IOHighscore::writeInFile.open("highscore.txt", std::ios::out | std::ios::app);
	if (!writeInFile)
	{
		std::cerr << "Could not open File";
	}
}

void IOHighscore::closeWrite()
{
	IOHighscore::writeInFile.close();
}

void IOHighscore::WriteHighscore(HighscoreManager& highscore)
{
	std::string hName = highscore.getName();
	int mPoints = highscore.getPoints();
	
	IOHighscore::openWrite();

	IOHighscore::writeInFile << hName << "," << mPoints << "\n";
	IOHighscore::closeWrite();
}