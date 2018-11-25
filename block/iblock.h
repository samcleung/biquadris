#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct IBlock : public Block {
	IBlock(const Coord& coord = Coord::blockStart(), int level = 0);
};

#endif
