#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "../block/block.h"

class Level {
public:
    virtual std::vector<Block> createBlock() = 0;
	Level();
	virtual ~Level() = 0;
};

Level *getLevel(int);

#endif
