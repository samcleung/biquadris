#ifndef __GRID_H__
#define __GRID_H__
#include <vector>
#include "../block/block.h"
#include "../cell/cell.h"

class Grid {
	std::vector<Block> onBoard;
	std::vector<vector<Cell*>> cells(15, std::vector<Cell*>(11, nullptr));
	
	public:
	bool addBlock(const Block&);
	bool addCells(const vector<Cell>&);
	bool updateCells(const vector<Cell>&, const vector<Cell>&);
	bool isValid(const vector<Cell>&);
	void drop(Block&);
	void print(int);
};

#endif
