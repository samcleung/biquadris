#ifndef __GRID_H__
#define __GRID_H__
#include <vector>
#include "../block/block.h"
#include "../cell/cell.h"

class Block;
class Cell;

class Grid {
	std::vector<Block> onBoard;
	std::vector<std::vector<Cell*>> cells = std::vector<std::vector<Cell*>>(15, std::vector<Cell*>(11, nullptr));
	
	public:
	void addBlock(const Block&);
	void addCells(const std::vector<Cell>&);
	void updateCells(std::vector<Cell>&, const std::vector<Cell>&);
	bool isValid(const std::vector<Cell>&);
	void drop(std::vector<Cell>&);
	void print(int);
};

#endif
