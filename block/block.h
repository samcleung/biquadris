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
	enum class Translation { Left = 0, Up, Right, Down };
	enum class Rotation { Clockwise = 4, CounterClockwise };

	int points = 0;

	bool rotate(Rotation, unsigned int count = 1);
	bool translate(Translation, unsigned int count = 1);
	std::vector<Coord> getCellCoords();
	
	protected:
	unsigned int dropBy = 0;
	unsigned int size;
	Grid* grid = nullptr;
	std::vector<Cell> cells;
	Block(int points, unsigned int dropBy, unsigned int size);

	public:
	Block(const Block& other);
	bool transform(const std::string& command);
	void drop();
	bool addToGrid(Grid* g);
	int getPoints() const;
};

#endif
