#ifndef __GRID_H__
#define __GRID_H__
#include <vector>
#include "../block/block.h"
#include "../cell/cell.h"

class Grid {
	vector<Block> onBoard;
	vector<vector<Cell*>> cells;
	
	public:
	// add ctrs & Big 5 as needed
	bool addBlock(Block&);
	bool updateBlock(Block*, Block&);
	bool isValid(Block*);
	void drop(Block&);
	void print(int);
};

#endif
