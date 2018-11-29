#ifndef __LEVEL3_H__
#define __LEVEL3_H__
#include <vector>
#include "level.h"

class Level3 : public Level{
	int seed;
	int score = 16;
	unsigned int dropBy = 1;
public:
	std::vector <Block> createBlock(bool isHeavy, int numberOfTurns) override;
	Level3(int seed); 
};

#endif
