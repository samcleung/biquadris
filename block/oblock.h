#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct OBlock : public Block {
	OBlock(int points = 0, unsigned int dropBy = 0, const Coord& coord = Coord::blockStart());
};

#endif
