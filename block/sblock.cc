#include <vector>
#include "block.h"
#include "sblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

SBlock::SBlock(const Coord& coord, int level) : Block{level, 3} {
	cells.emplace_back(Cell{'S', this, coord, Cell::Color::Cyan});
	cells.emplace_back(Cell{'S', this, Coord{coord.x + 1, coord.y}, Cell::Color::Cyan});
	cells.emplace_back(Cell{'S', this, Coord{coord.x + 1, coord.y + 1}, Cell::Color::Cyan});
	cells.emplace_back(Cell{'S', this, Coord{coord.x + 2, coord.y + 1}, Cell::Color::Cyan});
}
