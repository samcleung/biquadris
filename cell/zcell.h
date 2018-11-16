#ifndef __ZCELL_H__
#define __ZCELL_H__
#include "cell.h"
#include "../block/block.h"

class ZCell : public Cell {
	ZCell(Block*, int, int);
};

#endif
