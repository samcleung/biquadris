#ifndef __STARBLOCK_H__
#define __STARBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct StarBlock : Block {
	StarBlock(int points = 0, unsigned int dropBy = 0, const Coord& coord = Coord::blockStart());
};

#endif
