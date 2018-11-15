#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include <string>
#include "block.h"

class IBlock : Block {
	// add ctrs & Big 5 as needed
	bool rotate(Block::Rotation) override;
	bool translate(Block::Translation) override;
};

#endif
