#ifndef __LEVEL0_H__
#define __LEVEL0_H__
#include <vector>
#include <fstream>
#include "../block/block.h"
#include "level.h"

class Level0: public Level {
	std::ifstream & infile;
	public:
		std::vector <Block> createBlock() override;
		Level0();
		Level0(std::ifstream & infile); 
};

#endif
