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
	enum class Type { J, O, Z, I, L, S, T, None};
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
	//Copy Ctor
	Block(const Block& other);

	//Creates New block, originated at the Coord provided
	Block(const Block& other, const Coord& coord);

	//Clears all the cells from the block and also removes them from the grid
	//Not it invalidates- does not delete as everything is stack allocated
	void clear();

	//Rotates the block, count number of times in the Rotation specified
	void rotate(Rotation, unsigned int count = 1);

	//Moves the block count number of times in the direction (Translation) specified
	void translate(Translation, unsigned int count = 1);

	//Drops the Block in the grid
	void drop();

	//Adds this block to the grid provided
	bool addToGrid(Grid* g);

	//Returns how much the block is worth in terms of points. Note that each block is created
	// with score in the ctor
	int getPoints() const;
};

#endif
