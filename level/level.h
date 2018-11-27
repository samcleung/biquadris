#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "../block/block.h"

class Level {
public:
    virtual std::vector<Block*> createBlock() = 0;
	Level();
	~Level();
};

Level *getLevel(int);

#endif
