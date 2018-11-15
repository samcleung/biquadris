#ifndef __CELL_H__
#define __CELL_H__

struct Cell {
	enum Color { Green, Red, Blue, Yellow, Orange, Pink, Aqua, Brown };
	
	private:
	// add ctrs & Big 5 as needed
	Block* block;
	int x;
	int y;
};

#endif
