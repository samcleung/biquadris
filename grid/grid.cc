#include <iostream>
#include "grid.h"
#include "../block/block.h"

using namespace std;

Grid::Grid(int width, int height) : cells{vector<vector<Cell*>>(height, vector<Cell*>(width, nullptr))} {}

void Grid::addBlock(const Block& block) {
	onBoard.emplace_back(block);
}

// validates and adds individual cells to grid + list of modified cells
bool Grid::addCell(vector<Cell*>::const_iterator it, vector<Cell*>::const_iterator end) {
	Coord coord = (*it)->getCoord();
	if (it == end) {
		return true;
	} else if (!cells[coord.y][coord.x] && addCell(it + 1, end)) {
		cells[coord.y][coord.x] = *it;
		modified.emplace_back(coord);
		return true;
	} else {
		return false;
	}
}

// wraps call to addCell
bool Grid::addCells(const vector<Cell*>& cells) {
	return addCell(cells.begin(), cells.end());
}

// validates and moves cells in the grid + adds to the list of modified cells
bool Grid::moveCell(const Coord& oldCoord, const Coord& newCoord) {
	if (!cells[newCoord.y][newCoord.x]) {
		// add the cells to the list of modified cells
		modified.emplace_back(oldCoord);
		modified.emplace_back(newCoord);
		// move the cell
		cells[oldCoord.y][oldCoord.x]->setCoord(Coord{newCoord.x, newCoord.y});
		cells[newCoord.y][newCoord.x] = cells[oldCoord.y][oldCoord.x];
		cells[oldCoord.y][oldCoord.x] = nullptr;
		
		return true;
	}

	return false;
}

bool Grid::moveCells(const vector<Coord>& oldCoords, const vector<Coord>& newCoords) {
	unsigned int coordCount = oldCoords.size();
	if (coordCount == newCoords.size() && isValid(newCoords)) {
		for (unsigned int i = 0; i < coordCount; ++i) {
			moveCell(Coord{newCoords[i].y, newCoords[i].x}, Coord{oldCoords[i].y, oldCoords[i].x});
		}

		return true;
	}

	return false;
}

unsigned int Grid::shiftCells(unsigned int x = 0, unsigned int y = 0, unsigned int amount = 0) {
	if (x >= cells[y].size()) return 1;

	unsigned int filled = cells[y][x] ? shiftCells(x + 1, y, amount) : 0;
	bool isRowFull = filled == cells[y].size() - x;

	// move/remove cell if it exists
	if (cells[y][x]) {
		if (isRowFull) removeCell(Coord{x, y});
		else if (amount) moveCell(Coord{x, y}, Coord{x, y - amount});
	}

	if (x > 0) {
		return filled + 1;
	} else if (x == 0 && y < cells.size()) {
		return shiftCells(x, y + 1, amount + isRowFull);
	} else {
		return amount;
	}
}

void Grid::removeCell(const Coord& coord) {
	Cell* cell = cells[coord.y][coord.x];
	if (cell) {
		cell->remove();
		cell = nullptr;
	}
}

int Grid::updateCells(int level) {
	int points = level + shiftCells();
	return points * points;
}

int Grid::updateBlocks() {
	int points = 0;
	for (auto it = onBoard.begin(); it != onBoard.end(); ++it) {
		int p = it->getPoints();
		if (p != 0) {
			it = onBoard.erase(it);
			points += p;
		}
	}
	return points;
}

int Grid::updateGrid(int level) {
	return updateCells(level) + updateBlocks();
}

bool Grid::isValid(const vector<Coord>& coords) {
	for (const auto& coord: coords) {
		if (cells[coord.y][coord.x]) return false;
	}

	return true;
}

void Grid::drop(const vector<Coord>& coords) {
	// get min drop count
	int minDrop = -1;
	for (const auto &coord: coords) {
		for (int y = coord.y - 1; y >= 0; --y) {
			if (cells[y][coord.x]) {
				int drop = coord.y - y - 1;
				if (minDrop < 0 || drop < minDrop) minDrop = drop;
				break;
			}
		}
	}

	// drop all cells by min drop
	if (minDrop > 0) {
		for (const auto &coord: coords) {
			moveCell(coord, {coord.x, coord.y - minDrop});
		}
	}
}

void Grid::print(unsigned int row) {
	for (const auto& cell : cells[row]) {
		if (cell) cout << cell;
		else cout << ' ';
	};
}
