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
#include "command/command.h"

using namespace std;

// grid constants
const int width = 11;
const int height = 18;

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
	string input;
	while (cin >> input) {
		Command command{input};
		Block* curr = grid.currentBlock();
		int points = pow(level + 1, 2);
		switch (command) {
			case (int)Command::Action::Print:
				print(grid);
			case (int)Command::Action::I:
				curr = grid.addBlock(IBlock{points});
				break;
			case (int)Command::Action::J:
				curr = grid.addBlock(JBlock{points});
				break;
			case (int)Command::Action::L:
				grid.addBlock(LBlock{points});
				break;
			case (int)Command::Action::S:
				grid.addBlock(SBlock{points});
				break;
			case (int)Command::Action::I:
				grid.addBlock(IBlock{points});
				break;
			case (int)Command::Action::O:
				grid.addBlock(OBlock{points});
				break;
			case (int)Command::Action::T:
				grid.addBlock(TBlock{points});
				break;
			case (int)Command::Action::Z:
				grid.addBlock(ZBlock{points});
				break;
			case (int)Command::Action::Left:
				if (curr) curr->translate(Block::Translation::Left, command.multiplier);
				else cout << "ERROR no current block" << endl;
				break;
			case (int)Command::Action::Right:
				if (curr) curr->rotate(Block::Translation::Right, command.multiplier);
				else cout << "ERROR no current block" << endl;
				break;
			case (int)Command::Action::Down:
				if (curr) curr->rotate(Block::Translation::Down, command.multiplier);
				else cout << "ERROR no current block" << endl;
				break;
			case (int)Command::Action::Clockwise:
				if (curr) curr->rotate(Block::Rotation::Clockwise, command.multiplier);
				else cout << "ERROR no current block" << endl;
				break;
			case (int)Command::Action::CounterClockwise:
				if (curr) curr->rotate(Block::Rotation::CounterClockwise, command.multiplier);
				else cout << "ERROR no current block" << endl;
				break;
		}

/*

		if (command == Command::Action::PRINT) {
			print(grid);
		} else if (command == Command::Action::ADDBLOCK && !curr) {
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
					bool result = curr->transform(command);
					if (!result) cout << "ERROR: Invalid transform" << endl;
				}
			} else {
				cout << "ERROR: No current block" << endl;
			}
			print(grid);
		}

	}
*/
}
