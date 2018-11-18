#include "block.h"

using namespace std;

// command constants
// translations
const string LEFT = "left";
const string RIGHT = "right";
const string UP = "up";
const string DOWN = "down";
// rotations
const string CLOCKWISE = "clockwise";
const string COUNTERCLOCKWISE = "counterclockwise";
// block actions
const string DROP = "drop";

Block::Block(unsigned int size) : size{size} {}

vector<Cell> Block::copyCells() {
	vector<Cell> copy;
	for (auto cell : cells) {
		copy.emplace_back(cell);
	}
	return copy;
}

bool Block::rotate(Block::Rotation r) {
	vector<Cell> copy = copyCells();

	int originX = -1;
	int originY = -1;
	
	// get x and y of origin of block in grid
	for (auto &cell: cells) {
		if (originX < 0 || cell.x < originX) originX = cell.x;
		if (originY < 0 || cell.y < originY) originY = cell.y;
	}
	
	int minX = size;
	int minY = size;

	// rotate around (0,0) in a size*size grid
	for (auto &cell: copy) {
		int temp = cell.y;
		switch(r) {
			case Block::Rotation::CounterClockwise:
				cell.y = (cell.x - originX);
				cell.x = size - (temp - originY);
				break;
			default: // Block::Rotation::Clockwise
				cell.y = size - (cell.x - originX);
				cell.x = (temp - originY);
		}
	
		if (cell.y < minY) minY = cell.y;
		if (cell.x < minX) minX = cell.x;
	}

	// convert back to actual grid position
	for (auto &cell: copy) {
		cell.x += originX - minX;
		cell.y += originY - minY;
	}
	
	//return grid->updateBlock(*this, copy);
	return false;
}


bool Block::translate(Block::Translation t) {
	vector<Cell> copy = copyCells();
	
	// translate cells
	for (auto &cell: copy) {
		switch(t) {
			case Block::Translation::Left:
				cell.x += 1;
				break;
			case Block::Translation::Up:
				cell.y += 1;
				break;
			case Block::Translation::Right:
				cell.x -= 1;
				break;
			default: // Block::Translation::Down
				cell.y -= 1;
		}
	}

	//return grid->updateBlock(*this, copy);
	return false;
}


bool Block::transform(const string& command) {
	// block command interpreter
	if (command == LEFT) {
		return translate(Block::Translation::Left);
	} else if (command == RIGHT) {
		return translate(Block::Translation::Right);
	} else if (command == UP) {
		return translate(Block::Translation::Up);
	} else if (command == DOWN) {
		return translate(Block::Translation::Down);
	} else if (command == CLOCKWISE) {
		return rotate(Block::Rotation::Clockwise);
	} else if (command == COUNTERCLOCKWISE) {
		return rotate(Block::Rotation::CounterClockwise);
	}

	return false;
}

void Block::drop() {
	grid->drop(cells);
}

bool addToGrid(Grid* g) {
	//if (g->isValid(cells)) {
	//	g->addBlock(*this);
	//	g->addCells(cells);
	//	return true;
	//}

	return false;
}
