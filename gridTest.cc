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
const int height = 18;

// command constants
const string PRINT = "print";
const string ADDBLOCK = "add";	
const string DROP = "drop";

void print(Grid& g) {
	for (int i = height - 1; i >= 0; --i) {
		g.print(i);
		cout << endl;
	}
}

int main() {
	Grid grid{width, height};
	int level = 0;

	// command interpretter
	string command;
	while (cin >> command) {
		Block* curr = grid.currentBlock();
		if (command == PRINT) {
			print(grid);
		} else if (command == ADDBLOCK && !curr) {
			bool result;
			char type;
			if (cin >> type) {
				switch (type) {
					case 'j':
						result = grid.addBlock(JBlock{});
						break;
					case 'l':
						result = grid.addBlock(LBlock{});
						break;
					case 's':
						result = grid.addBlock(SBlock{});
						break;
					case 'i':
						result = grid.addBlock(IBlock{});
						break;
					case 'o':
						result = grid.addBlock(OBlock{});
						break;
					case 't':
						result = grid.addBlock(TBlock{});
						break;
					case 'z':
						result = grid.addBlock(ZBlock{});
				}
			}
			if (!result) cout << "ERROR: Could not add block" << endl;
			print(grid);
		} else {
			if (curr) {
				if (command == DROP) {
					curr->drop();
					print(grid);
					cout << "Points:" << grid.update(level) << endl;
				} else {
					bool result = curr->transform(command);
					if (!result) cout << "ERROR: Invalid transform" << endl;
				}
			} else {
				cout << "ERROR: No current block" << endl;
			}
			print(grid);
		}

	}
}
