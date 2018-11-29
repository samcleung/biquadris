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
	//Optional value if a seed is specified by the Client. This will throw an exception you 
	//try to ask for level 0 (as that requires a file to read form)
	static Level *getLevel(int level, int seed = 893);
	//getLevel purely for level 1. Throws an exception if you ask for any other level
	static Level *getLevel(int level, std::string stream);
};

#endif
