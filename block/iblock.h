#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct IBlock : public Block {
	IBlock(int points = 0, unsigned int dropBy = 0, const Coord& coord = Coord::blockStart());
};

#endif
