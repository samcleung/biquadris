#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct OBlock : public Block {
	OBlock(const Coord& coord = Coord::blockStart(), int level = 0);
};

#endif
