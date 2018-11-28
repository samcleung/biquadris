#include <vector>
#include "block.h"
#include "oblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

OBlock::OBlock(int points, unsigned int dropBy, const Coord& coord) : Block{points, dropBy, 2} {
	cells.emplace_back(Cell{'O', this, coord, Cell::Color::Magenta});
	cells.emplace_back(Cell{'O', this, Coord{coord.x + 1, coord.y}, Cell::Color::Magenta});
	cells.emplace_back(Cell{'O', this, Coord{coord.x, coord.y + 1}, Cell::Color::Magenta});
	cells.emplace_back(Cell{'O', this, Coord{coord.x + 1, coord.y + 1}, Cell::Color::Magenta});
}
