#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include <string>
#include "block.h"

class TBlock : Block {
	// add ctrs & Big 5 as needed
	bool rotate(Block::Rotation) override;
	bool translate(Block::Translation) override;
};

#endif
