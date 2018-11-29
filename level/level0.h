#ifndef __LEVEL0_H__
#define __LEVEL0_H__
#include <vector>
#include <string>
#include "../block/block.h"
#include "level.h"

class Level0: public Level {
	std::string infile;
	std::vector<char> commands;
	unsigned int position = 0;
	public:
		std::vector <Block> createBlock(bool isHeavy, int numberOfTurns) override;
		Level0();
		Level0(std::string infile); 
};

#endif
