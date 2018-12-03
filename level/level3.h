#ifndef __LEVEL3_H__
#define __LEVEL3_H__
#include <vector>
#include "level.h"
#include <string>
#include <vector>
class Level3 : public Level{
	bool readingFromScript = false;
	std::vector<char> blocksFromFile;
	int position = 0;
	int seed;
	int score = 16;
	unsigned int dropBy = 1;
	std::vector <Block> createBlockIMP(bool isHeavy, int numberOfTurns) override;
public:
	Level3(int seed); 
	Level3(std::string file);
};

#endif
