#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include <vector>
#include "../block/block.h"
#include "level.h"

class Level1: public Level {
	public:
		std::vector <Block> createBlock() override;
		Level1(int seed);
};

#endif
