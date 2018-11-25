#include <string>
#include <iostream>
#include <list>
#include "grid/grid.h"
#include "block/block.h"
#include "block/jblock.h"
#include "block/lblock.h"
#include "block/sblock.h"
#include "block/iblock.h"
#include "block/oblock.h"
#include "block/tblock.h"
#include "block/zblock.h"
#include "coord/coord.h"

using namespace std;

// grid constants
const int width = 11;
const int height = 15;

// command constants
const string PRINT = "print";
const string ADDBLOCK = "add";

void print(Grid& g) {
	for (int i = width - 1; i >= 0; --i) {
		g.print(i);
		cout << endl;
	}
}

int main() {
	Grid grid{width, height};

	list<Block> blocks;

	// command interpretter
	string command;
	while (cin >> command) {
		if (command == PRINT) {
			print(grid);
		} else if (command == ADDBLOCK) {
			char type;
			if (cin >> type) {
				switch (type) {
					case 'j':
						blocks.emplace_back(JBlock{});
						break;
					case 'l':
						blocks.emplace_back(LBlock{});
						break;
					case 's':
						blocks.emplace_back(SBlock{});
						break;
					case 'i':
						blocks.emplace_back(IBlock{});
						break;
					case 'o':
						blocks.emplace_back(OBlock{});
						break;
					case 't':
						blocks.emplace_back(TBlock{});
						break;
					case 'z':
						blocks.emplace_back(ZBlock{});
				}
			}
			cout << "Added new block to list of blocks" << endl;
			blocks.back().addToGrid(&grid);
			cout << "Added last block in list of blocks to grid" << endl;
		}
	}
}
