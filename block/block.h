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
	public:
	enum class Type { J, O, Z, I, L, S, T };
        enum class Translation { Left = 0, Up, Right, Down };
        enum class Rotation { Clockwise = 4, CounterClockwise };

	private:
	int points = 0;
	unsigned int dropBy = 0;
	unsigned int size = 0;
	Grid* grid = nullptr;
	std::vector<Coord> getCellCoords();	
	bool rotateCells(Rotation);
	bool translateCells(Translation);
	void applyDropBy();
	
	protected:
	std::vector<Cell> cells;
	Block(int points, unsigned int dropBy, unsigned int size);

	public:
	Block(const Block& other);
	Block(const Block& other, const Coord& coord);
	~Block();
	void rotate(Rotation, unsigned int count = 1);
	void translate(Translation, unsigned int count = 1);
	void drop();
	bool addToGrid(Grid* g);
	int getPoints() const;
};

#endif
