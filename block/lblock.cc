#include <vector>
#include "block.h"
#include "lblock.h"
#include "../cell/lcell.h"

LBlock::LBlock(int x, int y) : Block{vector<Cell*>{new LCell{x, y}, new LCell{x + 1, y}, new LCell{x + 2, y}, new LCell{x + 2, y + 1}}} {}
