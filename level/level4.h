#ifndef __LEVEL4_H__
#define __LEVEL4_H__
#include <vector>
#include "level.h"

class Level4: public Level{
	int seed;
	unsigned int dropBy = 1;
	int score = 25;
public:
	std::vector <Block> createBlock(bool isHeavy, int numberOfTurns) override;
	Level4(int seed); 
};

#endif
