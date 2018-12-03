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
	Grid(int width, int height);

	Block* addBlock(const Block& block); // adds a block to the grid
	Block* addBlocks(const std::vector<Block>& blocks); // adds multiple blocks to the grid, automatically dropping all but the last one
	bool addCells(const std::vector<Cell*>& cells); // adds cells to the grid, true if successful
	void removeCell(const Coord& coord); // removes a cell from the grid, making cell invalid in parent block
	bool moveCells(const std::vector<Coord>& oldCoords, const std::vector<Coord>& newCoords); // moves cells to new location - true if successful
	std::pair<int,int> update(int level); // updates all cells and blocks, returning the # of points earned (from cells & blocks) and # rows cleared
	void drop(const std::vector<Coord>& coords); // lowers the cells as low as possible, while maintaining shape
	void print(unsigned int row, Effect effect); // prints a grid row to text-display
	int getDropsSinceClear() const; // returns drops since clear 
};

#endif
