#ifndef __GRID_H__
#define __GRID_H__
#include <vector>
#include <list>
#include <utility>
#include "../block/block.h"
#include "../cell/cell.h"
#include "../coord/coord.h"
#include "../common/enums.h"

class Block;
class Cell;

class Grid {
	int dropsSinceClear = 0;
	Block* current = nullptr;
	std::list<Block> onBoard;
	std::vector<std::vector<Cell*>> cells;
	std::vector<Coord> modified; // stores all modified cells in a vector, to be redrawn in graphical display

	bool isValid(const std::vector<Coord>&); // returns true if coordinates contain no cells
	std::pair<int,int> updateCells(int); // updates cells on grid, returning the # of points earned (from cells only)
	int updateBlocks(); // updates block list, removing empty blocks and returning the # of points earned (from blocks only)
	unsigned int shiftCells(unsigned int, unsigned int, unsigned int, unsigned int); // recursively shifts cells downward according to rows that have been removed, returns number of rows removed
	bool addCell(std::vector<Cell*>::const_iterator&, std::vector<Cell*>::const_iterator&);
	bool moveCell(const Coord&, const Coord&);

	public:
	//Ctor for grid. 
	Grid(int width, int height);

	//Adds a block to the grid.
	//Returns a pointer to the new block. Returns nullptr if unable to add the block
	Block* addBlock(const Block& block);

	//Adds multiple blocks to the grid, dropping all blocks but the last one
	//Returns a pointer to the LAST block. Retruns nullptr if unable to add the Block
	Block* addBlocks(const std::vector<Block>& blocks);

	//Adds cells to the grid. Returns true if successful, false otherwise
	bool addCells(const std::vector<Cell*>& cells);
	
	//Removes a cell from the grid, making it invalid in the block that owns that cell
	void removeCell(const Coord& coord);

	//Moves cells to a new location. Returns true if successful, false otherwise
	bool moveCells(const std::vector<Coord>& oldCoords, const std::vector<Coord>& newCoords);

	//Updates all cells and blocks. Basically checks if any rows can be deleted.
	//Returns a pair: (# of points earned, # of rows cleared)
	std::pair<int,int> update(int level);

	void drop(const std::vector<Coord>& coords, bool countable); // lowers the cells as low as possible, while maintaining shape

	//Prints the indicated row on to std::cout. Applies the blind effect if specified. 
	void print(unsigned int row, Effect effect);

	//Returns number of blocks that have been dropped since the last clear
	int getDropsSinceClear() const;
};

#endif
