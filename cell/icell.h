#ifndef __ICELL_H__
#define __ICELL_H__
#include "cell.h"
#include "../block/block.h"

class ICell : public Cell {
	ICell(Block*, int, int);
};

#endif
