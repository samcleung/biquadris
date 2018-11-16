#ifndef __OCELL_H__
#define __OCELL_H__
#include "cell.h"
#include "../block/block.h"

class OCell : public Cell {
	OCell(Block*, int, int);
};

#endif
