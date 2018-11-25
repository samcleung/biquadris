#ifndef __GRID_H__
#define __GRID_H__
#include <vector>
#include <list>
#include "../block/block.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

class Block;
class Cell;

class Grid {
	std::list<Block> onBoard;
	std::vector<std::vector<Cell*>> cells;
	std::vector<Coord> modified; // stores all modified cells in a vector, to be redrawn in graphical display

	bool isValid(const std::vector<Coord>&); // returns true if coordinates contain no cells
	int updateCells(int); // updates cells on grid, returning the # of points earned (from cells only)
	int updateBlocks(); // updates block list, removing empty blocks and returning the # of points earned (from blocks only)
	unsigned int shiftCells(unsigned int, unsigned int, unsigned int); // recursively shifts cells downward according to rows that have been removed, returns number of rows removed
	void removeCell(const Coord&); // removes a cell from the grid, making cell invalid in parent block
	bool addCell(std::vector<Cell*>::const_iterator, std::vector<Cell*>::const_iterator);
	bool moveCell(const Coord&, const Coord&);

	public:
	Grid(int, int);

	void addBlock(const Block& blocks); // adds a block to the grid
	bool addCells(const std::vector<Cell*>& cells); // adds cells to the grid, true if successful
	bool moveCells(const std::vector<Coord>& oldCoords, const std::vector<Coord>& newCoords); // moves cells to new location - true if successful
	int updateGrid(int level); // updates all cells and blocks, returning the # of points earned (from cells & blocks)
	void drop(const std::vector<Coord>& coords); // lowers the cells as low as possible, while maintaining shape
	void print(unsigned int row); // prints a grid row to text-display
};

#endif
