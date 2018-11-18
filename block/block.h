#ifndef __BLOCK_H_
#define __BLOCK_H_
#include <string>
#include <vector>
#include "../grid/grid.h"
#include "../cell/cell.h"

// forward declarations (otherwise, circular includes)
class Grid;

class Block {
	enum class Translation { Left = 0, Up, Right, Down };
	enum class Rotation { Clockwise = 4, Counterclockwise };
	bool rotate(Rotation);
	bool translate(Translation);
	std::vector<Cell> copyCells();
	
	protected:
	unsigned int dropBy = 0;
	const unsigned int size;
	Grid* grid = nullptr;
	std::vector<Cell> cells;

	public:
	Block(unsigned int);
	bool transform(const std::string&);
	void drop();
	bool addToGrid(Grid* g); // todo
};

#endif
