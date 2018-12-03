#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include <vector>
#include "level.h"

class Level2: public Level {
	int seed;
	int score = 9;
	std::vector <Block> createBlockIMP(bool isHeavy, int numberOfTurns) override;
public:
	Level2( int seed); 
};

#endif
