#ifndef __LEVEL4_H__
#define __LEVEL4_H__
#include "level.h"
#include <vector>
#include <string>
class Level4: public Level{
	int seed;
	bool isFromFile = false;
	std::vector <char> readFromFile;
	int position = 0;
	unsigned int dropBy = 1;
	int score = 25;
	std::vector <Block> createBlockIMP(bool isHeavy, int numberOfTurns) override;
public:
	Level4(int seed); 
	Level4(std::string blockFile);
};

#endif
