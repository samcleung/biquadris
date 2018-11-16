#include "cell.h"
#include "jcell.h"
#include "../block/block.h"

JCell::JCell(Block* block, int x, int y) {'J', block, x, y, Cell::Color::Green} {}
