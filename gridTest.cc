#include <string>
#include <iostream>
#include <list>
#include <cmath>
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
// translations
const string LEFT = "left";
const string RIGHT = "right";
const string UP = "up";
const string DOWN = "down";
// rotations
const string CLOCKWISE = "clockwise";
const string COUNTERCLOCKWISE = "counterclockwise";


void print(Grid& g) {
	for (int i = height - 1; i >= 0; --i) {
		g.print(i);
		cout << endl;
	}
}

bool transform(Block& block, const string& command) {
        // block command interpreter
        if (command == LEFT) {
                return block.translate(Block::Translation::Left);
        } else if (command == RIGHT) {
                return block.translate(Block::Translation::Right);
        } else if (command == UP) {
                return block.translate(Block::Translation::Up);
        } else if (command == DOWN) {
                return block.translate(Block::Translation::Down);
        } else if (command == CLOCKWISE) {
                return block.rotate(Block::Rotation::Clockwise);
        } else if (command == COUNTERCLOCKWISE) {
                return block.rotate(Block::Rotation::CounterClockwise);
        }

        return false;
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
				int points = pow(level + 1, 2);
				switch (type) {
					case 'j':
						result = grid.addBlock(JBlock{points});
						break;
					case 'l':
						result = grid.addBlock(LBlock{points});
						break;
					case 's':
						result = grid.addBlock(SBlock{points});
						break;
					case 'i':
						result = grid.addBlock(IBlock{points});
						break;
					case 'o':
						result = grid.addBlock(OBlock{points});
						break;
					case 't':
						result = grid.addBlock(TBlock{points});
						break;
					case 'z':
						result = grid.addBlock(ZBlock{points});
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
					bool result = transform(*curr, command);
					if (!result) cout << "ERROR: Invalid transform" << endl;
				}
			} else {
				cout << "ERROR: No current block" << endl;
			}
			print(grid);
		}

	}
}
