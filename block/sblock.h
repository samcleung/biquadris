#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct SBlock : public Block {
	SBlock(int points = 0, unsigned int dropBy = 0, const Coord& coord = Coord::blockStart());
};

#endif
