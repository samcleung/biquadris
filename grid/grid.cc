


bool addBlock(Block& block) {
	// todo
}

bool updateBlock(Block& oldBlock, const Block* newBlock) {
	// todo
}

bool Grid::isValid(const Block& block) {
	// todo
}

void Grid::drop(Block&) {
	// todo 
}

void Grid::print(int row) {
	for (auto& cell : cells[row]) cell->print();
}
