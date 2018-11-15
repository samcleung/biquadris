#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include <string>
#include "block.h"

class SBlock : Block {
	// add ctrs & Big 5 as needed
	bool rotate(Block::Rotation) override;
	bool translate(Block::Translation) override;
};

#endif
