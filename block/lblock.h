#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct LBlock : public Block {
	LBlock(const Coord& coord = Coord::blockStart(), int level = 0);
};

#endif
