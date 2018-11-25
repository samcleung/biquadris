#include <vector>
#include "block.h"
#include "iblock.h"
#include "../cell/cell.h"
#include "../coord/coord.h"

IBlock::IBlock(const Coord& coord, int level) : Block{level, 4} {
	cells.emplace_back(Cell{'I', this, coord, Cell::Color::Red});
	cells.emplace_back(Cell{'I', this, Coord{coord.x + 1, coord.y}, Cell::Color::Red});
	cells.emplace_back(Cell{'I', this, Coord{coord.x + 2, coord.y}, Cell::Color::Red});
	cells.emplace_back(Cell{'I', this, Coord{coord.x + 3, coord.y}, Cell::Color::Red});
}
