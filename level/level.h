#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <memory>
#include <vector>
#include <string>
#include "../block/block.h"

class Level {
	//Private Implementation of the Public method createBlock.
	virtual std::vector<Block> createBlockIMP(bool isHeavy, int numberOfTurns) = 0;
public:
	//Public wrapper for createBlock.
		//isHeavy: Is the Block under the Effect Heavy
		//numberOfTurns: Number of Turns elasped since a  row was cleared from the board.
	std::vector<Block> createBlock(bool isHeavy, int numberOfTurns);
	Level();
	virtual ~Level();

	//Static Method returning a pointer to a Level, determined by the provided int, level
	//Optional value if a seed or a sequence file is specified by the Client
	static std::unique_ptr<Level> getLevel(int level, int seed = 893, std::string stream = "sequence1.txt");


	//Only takes in a sequence file (no option for seed). Used for implementing norandom 
	// and random options in level 3 and 4
	static std::unique_ptr<Level> getLevel(int level, std::string stream);
};

#endif
