#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include <string>
#include "../block/block.h"

class Level {
public:
	virtual std::vector<Block> createBlock(bool isHeavy, int numberOfTurns) = 0;
	Level();
	virtual ~Level();
	//Optional value if a seed or sequence file is specified by the Client
	static Level *getLevel(int level, int seed = 893, std::string stream = "sequence1.txt");
	//getLevel purely for level 1. Throws an exception if you ask for any other level
	static Level *getLevel(int level, std::string stream);
};

#endif
