#ifndef __JCELL_H__
#define __JCELL_H__
#include "cell.h"
#include "../block/block.h"

class JCell : public Cell {
	JCell(Block*, int, int);
};

#endif
