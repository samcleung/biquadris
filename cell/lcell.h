#ifndef __LCELL_H__
#define __LCELL_H__
#include "cell.h"
#include "../block/block.h"

class LCell : public Cell {
	LCell(Block*, int, int);
};

#endif
