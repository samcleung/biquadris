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
	Block* curr = nullptr;

	// command interpretter
	string input;
	while (cin >> input) {
		Command command{input};
		int points = pow(level + 1, 2);
		switch (command) {
			case (int)Command::Action::Print:
				print(grid);
				break;
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
				else cout << "ERROR: no current block" << endl;
				break;
			case (int)Command::Action::Right:
				if (curr) curr->translate(Block::Translation::Right, command.multiplier);
				else cout << "ERROR: no current block" << endl;
				break;
			case (int)Command::Action::Down:
				if (curr) curr->translate(Block::Translation::Down, command.multiplier);
				else cout << "ERROR: no current block" << endl;
				break;
			case (int)Command::Action::Clockwise:
				if (curr) curr->rotate(Block::Rotation::Clockwise, command.multiplier);
				else cout << "ERROR: no current block" << endl;
				break;
			case (int)Command::Action::CounterClockwise:
				if (curr) curr->rotate(Block::Rotation::CounterClockwise, command.multiplier);
				else cout << "ERROR: no current block" << endl;
				break;
			case (int)Command::Action::Drop:
				if (curr) curr->drop();
				else cout << "ERROR: no current block" << endl;
				break;
			default:
				cout << "ERROR: invalid command" << endl;
				break;
		}
	}
}
