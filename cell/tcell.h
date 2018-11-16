#ifndef __TCELL_H__
#define __TCELL_H__
#include "cell.h"
#include "../block/block.h"

class TCell : public Cell {
	TCell(Block*, int, int);
};

#endif
