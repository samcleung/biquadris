#ifndef __BLOCK_H_
#define __BLOCK_H_
#include <string>
#include <vector>
#include "../grid/grid.h"
#include "../cell/cell.h"

class Block {
	protected:
	// enums
	enum Translation { left = 0, up, right, down };
        enum Rotation { clockwise = 4, counterclockwise };

	// properties
	bool isHeavy;
	unsigned int dropBy;
	Grid* grid;
	vector<Cell*> cells;

	// methods
	virtual bool rotate(Rotation r);
	virtual bool translate(Translation t);

	public:
	// add ctrs & Big 5 as needed
	bool makeMove(const std::string&);
};

#endif
