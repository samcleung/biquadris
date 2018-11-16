#include <iostream>
#include "grid.h"
#include "../block/block.h"

bool Grid::addBlock(Block& block) {
	// todo
}

bool Grid::updateBlock(Block& oldBlock, const Block* newBlock) {
	// todo
}

bool Grid::isValid(const Block& block) {
	// todo
}

void Grid::drop(Block&) {
	// todo 
}

void Grid::print(int row) {
	for (auto& cell : cells[row]) cout << cell;
}
