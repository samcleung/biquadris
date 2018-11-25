#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct TBlock : public Block {
	TBlock(const Coord& coord = Coord::blockStart(), int level = 0);
};

#endif
