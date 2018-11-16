#ifndef __BLOCK_H_
#define __BLOCK_H_
#include <string>
#include <vector>
#include "../grid/grid.h"
#include "../cell/cell.h"

class Block {
	enum class Translation { Left = 0, Up, Right, Down };
	enum class Rotation { Clockwise = 4, Counterclockwise };
	bool rotate(Rotation);
	bool translate(Translation);

	protected:
	unsigned int dropBy = 0;
	Grid* grid = nullptr;
	vector<Cell*> cells;

	public:
	bool transform(const std::string&);
	void drop();
};

#endif
