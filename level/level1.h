#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include <vector>
#include "../block/block.h"
#include "level.h"

class Level1: public Level {
	const int score = 4;
	unsigned int seed;
	public:
		std::vector <Block> createBlock(bool isHeavy, int numberOfTurns) override;
		Level1(unsigned int seed);
};

#endif
