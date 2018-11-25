#ifndef __STARBLOCK_H__
#define __STARBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct StarBlock : Block {
	StarBlock(const Coord& coord = Coord::blockStart(), int level = 3);
};

#endif
