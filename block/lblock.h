#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct LBlock : public Block {
	LBlock(int points = 0, unsigned int dropBy = 0, const Coord& coord = Coord::blockStart());
};

#endif
