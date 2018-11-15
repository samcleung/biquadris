#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include <string>
#include "block.h"

class ZBlock : Block {
	// add ctrs & Big 5 as needed
	bool rotate(Block::Rotation) override;
	bool translate(Block::Translation) override;
};

#endif
