#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include <string>
#include "block.h"

class LBlock : Block {
	// add ctrs & Big 5 as needed
	bool rotate(Block::Rotation) override;
	bool translate(Block::Translation) override;
};

#endif