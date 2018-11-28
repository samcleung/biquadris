#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct JBlock : public Block {
	JBlock(int points = 0, unsigned int dropBy = 0, const Coord& coord = Coord::blockStart());
};

#endif
