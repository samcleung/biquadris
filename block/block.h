#ifndef __BLOCK_H_
#define __BLOCK_H_
#include <string>
#include <vector>
#include "../grid/grid.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

// forward declarations (otherwise, circular includes)
class Grid;

class Block {
	int points = 0;
	unsigned int dropBy = 0;
	unsigned int size = 0;
	Grid* grid = nullptr;
	std::vector<Coord> getCellCoords();
	
	protected:
	std::vector<Cell> cells;
	Block(int points, unsigned int dropBy, unsigned int size);

	public:
	enum class Translation { Left = 0, Up, Right, Down };
        enum class Rotation { Clockwise = 4, CounterClockwise };
	
	Block(const Block& other);
	~Block();
	bool rotate(Rotation, unsigned int count = 1);
	bool translate(Translation, unsigned int count = 1);
	void drop();
	bool addToGrid(Grid* g);
	int getPoints() const;
};

#endif
