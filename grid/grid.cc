#include <iostream>
#include "grid.h"
#include "../block/block.h"

using namespace std;

void Grid::addBlock(const Block& block) {
	onBoard.emplace_back(block);
}

void Grid::addCells(const vector<Cell>& cells) {
	for (auto cell : cells)
		vector[cell.y][cell.x] = &cell;
}

void Grid::updateCells(vector<Cell>& oldCells, const vector<Cell>& newCells) {
	for (int i = 0; i < oldCells.size(); ++i) {
		cells[oldCells[i].y][oldCells[i].x] = nullptr; // remove old cell
		oldCells[i].x = newCells[i].x; // update old cell x to new x
                oldCells[i].y = newCells[i].y; // update old cell y to new y
		cells[oldCells[i].y][oldCells[i].x] = oldCells[i]; // add updated, old cell
	}
}

bool Grid::isValid(const vector<Cell>& cells) {
	for (auto cell : cells)
		if (this->cells[cell.y][cell.x]) return false;
	return true;
}

void Grid::drop(vector<Cell>& cells) {
	// get min drop count
	unsigned int minDrop = -1;
	for (auto &cell : cells) {
		for (int i = cell.x - 1; i >= 0; --i)
			if (this->cells[i]) {
				int drop = cell.x - i - 1;
				if (minDrop < 0 || drop < minDrop) minDrop = drop;
				break;
			}
	}

	// drop all cells by min drop
	if (minDrop > 0) {
		for (auto &cell : cells) {
			this->cells[cell.y][cell.x] = nullptr;
			cell.x -= minDrop;
			this->cells[cell.y][cell.x] = &cell;
		}
	}
}

void Grid::print(int row) {
	for (auto& cell : cells[row]) cout << cell;
}
