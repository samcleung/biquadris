#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include <string>
#include "block.h"

class OBlock : Block {
	// add ctrs & Big 5 as needed
	bool rotate(Block::Rotation) override;
	bool translate(Block::Translation) override;
};

#endif
