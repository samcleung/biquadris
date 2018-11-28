#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct ZBlock : public Block {
	ZBlock(int points = 0, unsigned int dropBy = 0, const Coord& coord = Coord::blockStart());
};

#endif
