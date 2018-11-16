#ifndef __SCELL_H__
#define __SCELL_H__
#include "cell.h"
#include "../block/block.h"

class SCell : public Cell {
	SCell(Block*, int, int);
};

#endif
