#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include <string>
#include "block.h"

class JBlock : Block {
	// add ctrs & Big 5 as needed
	bool rotate(Block::Rotation) override;
	bool translate(Block::Translation) override;
};

#endif
