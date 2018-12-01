#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <cmath>
#include "grid.h"
#include "../block/block.h"

using namespace std;

Grid::Grid(int width, int height) : cells{vector<vector<Cell*>>(height, vector<Cell*>(width, nullptr))} {}

Block* Grid::addBlock(const Block& block) {
	// if current already exists, remove it
	if (current) {
		onBoard.pop_back();
		current = nullptr;
	}
	// add block as last block on the grid
	onBoard.emplace_back(block);
	// set current to be address of last block
	current = &(*onBoard.rbegin());
	// try to add board with cells to the grid
	bool result = current->addToGrid(this);
	// pop last block if it cannot be added
	if (!result) {
		onBoard.pop_back();
		current = nullptr;
	}
	return current;
}

Block* Grid::addBlocks(const vector<Block>& blocks) {
	Block* result;
	for (auto it = blocks.begin(), last = prev(blocks.end()); it != blocks.end(); ++it) {
		result = addBlock(*it);
		if (!result) return nullptr;
		if (it != last) result->drop();
	}
	return result;
}

// validates and adds individual cells to grid + list of modified cells
bool Grid::addCell(vector<Cell*>::const_iterator& it, vector<Cell*>::const_iterator&end) {
	if (it != end) {
		Cell* cell = (*it);
		Coord coord = cell->getCoord();

		if (!cells[coord.y][coord.x] && addCell(++it, end)) {
			cells[coord.y][coord.x] = cell;
			modified.emplace_back(coord);
		} else {
			return false;
		}
	}

	return true;
}

// wraps call to addCell
bool Grid::addCells(const vector<Cell*>& cells) {
	auto begin = cells.begin();
	auto end = cells.end();
	return addCell(begin, end);
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
	// get coordinates from newCoords that do not exist in oldCoords
	vector<Coord> toCoords;
	for (const auto& coord: newCoords) {
		if (find(oldCoords.begin(), oldCoords.end(), coord) == oldCoords.end()) {
			toCoords.emplace_back(coord);
		}
	}

	// get coordinates from oldCoords that do not exist in newCoords
	vector<Coord> fromCoords;
	for (const auto& coord: oldCoords) {
		if (find(newCoords.begin(), newCoords.end(), coord) == newCoords.end()) {
			fromCoords.emplace_back(coord);
		}
	}

	
	unsigned int coordCount = fromCoords.size();
	if (coordCount == toCoords.size() && isValid(toCoords)) {
		for (unsigned int i = 0; i < coordCount; ++i) {
			moveCell(fromCoords[i], toCoords[i]);
		}

		return true;
	}

	return false;
}

unsigned int Grid::shiftCells(unsigned int x = 0, unsigned int y = 0, unsigned int filledLeft = 0, unsigned int amount = 0) {
	if (x >= cells[y].size()) return 0;

	bool isFilled = cells[y][x];
	unsigned int filledRight = shiftCells(x + 1, y, filledLeft + isFilled, amount);
	bool isRowFull = (filledLeft + filledRight + isFilled) == cells[y].size();

	// move/remove cell if it exists
	if (isFilled) {
		if (isRowFull) removeCell(Coord{x, y});
		else if (amount) moveCell(Coord{x, y}, Coord{x, y - amount});
	}

	if (x > 0) {
		return filledRight + isFilled;
	} else if (x == 0 && y < cells.size() - 1) {
		return shiftCells(0, y + 1, 0, amount + isRowFull);
	} else {
		return amount;
	}
}

void Grid::removeCell(const Coord& coord) {
	Cell* cell = cells[coord.y][coord.x];
	if (cell) {
		cell->remove();
		cells[coord.y][coord.x] = nullptr;
	}
}

int Grid::updateCells(int level) {
	return pow(level + shiftCells(), 2);
}

int Grid::updateBlocks() {
	int points = 0;
	for (auto it = onBoard.begin(); it != onBoard.end();) {
		int p = it->getPoints();
		if (p != 0) {
			it = onBoard.erase(it);
			points += p;
		} else {
			++it;
		}
	}
	return points;
}

int Grid::update(int level) {
	return updateCells(level) + updateBlocks();
}

bool Grid::isValid(const vector<Coord>& coords) {
	for (const auto& coord: coords) {
		if (coord.y >= cells.size() || coord.x >= cells[coord.y].size() || cells[coord.y][coord.x]) return false;
	}
	return true;
}

void Grid::drop(const vector<Coord>& coords) {
	// get lowest cell in each column of the coords
	vector<Coord> lowest;
	map<unsigned int, set<unsigned int>> setMap;

	for (const auto& coord: coords)
		setMap[coord.x].insert(coord.y);
	for (const auto& map: setMap)
		lowest.emplace_back(Coord{map.first, *map.second.begin()});

	// get min drop count
	int minDrop = -1;
	for (const auto& coord: lowest) {
		for (int y = coord.y - 1; y >= 0; --y) {
			if (cells[y][coord.x] || y == 0) {
				int drop = coord.y - y - (bool)cells[y][coord.x];
				if (minDrop < 0 || drop < minDrop) minDrop = drop;
				break;
			}
		}
	}

	// drop all cells by min drop
	if (minDrop > 0) {
		// new coordinates of
		vector<Coord> newCoords;

		for (const auto &coord: coords) {
			newCoords.emplace_back(Coord{coord.x, coord.y - minDrop});
		}
		
		moveCells(coords, newCoords);
	}
	
	// clear current
	current = nullptr;
}

void Grid::print(unsigned int row) {
	// print left border of grid
	cout << "|";
	
	// print cell
	for (const auto& cell : cells[row]) {
		if (cell) cout << *cell;
		else cout << ' ';
	};
	
	// print right border of grid
	cout << "|";
}
