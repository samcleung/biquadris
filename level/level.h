#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "../block/block.h"

class Level {
public:
	virtual std::vector<Block> createBlock() = 0;
	Level();
	virtual ~Level();
	static Level *getLevel(int level, int seed = 893);
	static Level *getLevel(int level, std::ifstream &stream);
};

#endif
