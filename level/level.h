#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "../block/block.h"

class Level {
	virtual std::vector<Block*> createBlock() = 0;
public:
	Level();
	~Level();
};

#endif
