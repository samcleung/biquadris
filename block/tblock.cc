#include <vector>
#include "block.h"
#include "tblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

TBlock::TBlock(int points, unsigned int dropBy, const Coord& coord) : Block{points, dropBy, 3} {
	cells.emplace_back(Cell{'T', this, Coord{coord.x + 1, coord.y}, Cell::Color::Default});
	cells.emplace_back(Cell{'T', this, Coord{coord.x, coord.y + 1}, Cell::Color::Default});
	cells.emplace_back(Cell{'T', this, Coord{coord.x + 1, coord.y + 1}, Cell::Color::Default});
	cells.emplace_back(Cell{'T', this, Coord{coord.x + 2, coord.y + 1}, Cell::Color::Default});
}
