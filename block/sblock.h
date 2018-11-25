#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct SBlock : public Block {
	SBlock(const Coord& coord = Coord::blockStart(), int level = 0);
};

#endif
