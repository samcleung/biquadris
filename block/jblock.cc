#include <vector>
#include "block.h"
#include "jblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

JBlock::JBlock(const Coord& coord, int level) : Block{level, 3} {
	cells.emplace_back(Cell{'J', this, coord, Cell::Color::Green});
	cells.emplace_back(Cell{'J', this, Coord{coord.x, coord.y + 1}, Cell::Color::Green});
	cells.emplace_back(Cell{'J', this, Coord{coord.x + 1, coord.y}, Cell::Color::Green});
	cells.emplace_back(Cell{'J', this, Coord{coord.x + 2, coord.y}, Cell::Color::Green});
}
