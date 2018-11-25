#include <vector>
#include "block.h"
#include "tblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

TBlock::TBlock(const Coord& coord, int level) : Block{level, 3} {
	cells.emplace_back(Cell{'T', this, Coord{coord.x + 1, coord.y}, Cell::Color::Default});
	cells.emplace_back(Cell{'T', this, Coord{coord.x, coord.y + 1}, Cell::Color::Default});
	cells.emplace_back(Cell{'T', this, Coord{coord.x + 1, coord.y + 1}, Cell::Color::Default});
	cells.emplace_back(Cell{'T', this, Coord{coord.x + 2, coord.y + 1}, Cell::Color::Default});
}
