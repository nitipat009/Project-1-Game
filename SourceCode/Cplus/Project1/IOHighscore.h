
//IOHighscore.h

#ifndef IOHIGHSCORE_H
#define IOHIGHSCORE_H

#include <iostream>
#include <fstream>
#include <string>
#include "HighscoreManager.h"

class IOHighscore
{
public:

	void WriteHighscore(HighscoreManager& highscore);

private:

	std::ofstream writeInFile;

	void openWrite();

	void closeWrite();
};
#endif