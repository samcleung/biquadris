#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct ZBlock : public Block {
	ZBlock(const Coord& coord = Coord::blockStart(), int level = 0);
};

#endif
