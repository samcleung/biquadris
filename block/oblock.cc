#include <vector>
#include "block.h"
#include "oblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

OBlock::OBlock(const Coord& coord, int level) : Block{level, 2} {
	cells.emplace_back(Cell{'O', this, coord, Cell::Color::Magenta});
	cells.emplace_back(Cell{'O', this, Coord{coord.x + 1, coord.y}, Cell::Color::Magenta});
	cells.emplace_back(Cell{'O', this, Coord{coord.x, coord.y + 1}, Cell::Color::Magenta});
	cells.emplace_back(Cell{'O', this, Coord{coord.x + 1, coord.y + 1}, Cell::Color::Magenta});
}
