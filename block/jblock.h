#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"
#include "../coord/coord.h"

struct JBlock : public Block {
	JBlock(const Coord& coord = Coord::blockStart(), int level = 0);
};

#endif
