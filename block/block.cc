#include "block.h"

using namespace std;

Block::Block(int points, unsigned int dropBy, bool countable, unsigned int size) : points{points}, dropBy{dropBy}, countable{countable}, size{size} {}

Block::Block(const Block& other) : points{other.points}, dropBy{other.dropBy}, countable{other.countable}, size{other.size}, grid{other.grid} {
	for (const auto& cell: other.cells) cells.emplace_back(Cell{cell, this});
}

Block::Block(const Block& other, const Coord& newCoord) {
	bool isOriginXSet = false;
	unsigned int originX;
	bool isOriginYSet = false;
	unsigned int originY;
	
	// get originX and originY of cells
	for (const auto& cell: other.cells) {
		if (cell.isValid()) {
			// copy cell to new block
			cells.emplace_back(Cell{cell, this});
			// get coordinate of cell and set originX/originY
			Coord coord = cell.getCoord();
			if (!isOriginXSet || coord.x < originX) {
				isOriginXSet = true;
				originX = coord.x;
			}
			if (!isOriginYSet || coord.y < originY) {
				isOriginYSet = true;
				originY = coord.y;
			}
		}
	}

	// change cells to have coord with newCoord as origin
	for (auto& cell: cells) {
		Coord coord = cell.getCoord();
		cell.setCoord(Coord{coord.x - originX + newCoord.x, coord.y - originY + newCoord.y});
	}
}

void Block::clear() {
	if (grid) {
		vector<Coord> coords = getCellCoords();
		for (const auto& coord: coords) grid->removeCell(coord);
	} else {
		for (auto& cell: cells) cell.remove();
	}
}

vector<Coord> Block::getCellCoords() {
	vector<Coord> coords;
	for (const auto& cell: cells) {
		if (cell.isValid()) coords.emplace_back(cell.getCoord());
	}
	return coords;
}

bool Block::rotateCells(Block::Rotation r) {
	vector<Coord> newCoords;

	bool isOriginXSet = false;
	unsigned int originX;
	bool isOriginYSet = false;
	unsigned int originY;

	// make cell coordinate copies for transformation, get x and y of origin of block in grid
	for (const auto& cell: cells) {
		if (cell.isValid()) {
			newCoords.emplace_back(cell.getCoord());
			const Coord& coord = newCoords.rbegin()[0];
			if (!isOriginXSet || coord.x < originX) {
				isOriginXSet = true;
				originX = coord.x;
			}
			if (!isOriginYSet || coord.y < originY) {
				isOriginYSet = true;
				originY = coord.y;
			}
		}
	}

	unsigned int minX = size;
	unsigned int minY = size;

	// rotate around (0,0) in a size*size grid
	for (auto &coord: newCoords) {
		int temp = coord.y;
		switch(r) {
			case Block::Rotation::CounterClockwise:
				coord.y = (coord.x - originX);
				coord.x = size - (temp - originY);
				break;
			default: // Block::Rotation::Clockwise
				coord.y = size - (coord.x - originX);
				coord.x = (temp - originY);
		}

		if (coord.y < minY) minY = coord.y;
		if (coord.x < minX) minX = coord.x;
	}

	// convert back to actual grid position
	for (auto &coord: newCoords) {
		coord.x += originX - minX;
		coord.y += originY - minY;
	}
		
	return grid->moveCells(getCellCoords(), newCoords);
}

void Block::rotate(Block::Rotation r, unsigned int count) {
	bool success = true;
	for (unsigned int i = 0; success && i < count; ++i) {
		success = rotateCells(r);
		if (success) applyDropBy();
	}
}

bool Block::translateCells(Block::Translation t) {
	vector<Coord> newCoords;

	// translate cells
	for (const auto& cell: cells) {
		Coord coord = cell.getCoord();
		switch(t) {
			case Block::Translation::Left:
				if (coord.x < 1) return false; // cannot go below 0
				coord.x -= 1;
				break;
			case Block::Translation::Up:
				coord.y += 1;
				break;
			case Block::Translation::Right:
				coord.x += 1;
				break;
			default: // Block::Translation::Down
				if (coord.y < 1) return false; // cannot go below 0
				coord.y -= 1;
		}

		newCoords.emplace_back(coord);
	}
	
	return grid->moveCells(getCellCoords(), newCoords);
}



void Block::translate(Block::Translation t, unsigned int count) {
	bool success = true;
	for (unsigned int i = 0; success && i < count; ++i) {
		success = translateCells(t);
		if (success) applyDropBy();
	}
}

void Block::applyDropBy() {
	for (unsigned int i = 0; i < dropBy; ++i) {
		if (!translateCells(Block::Translation::Down)) break;
	}
}

void Block::drop() {
	grid->drop(getCellCoords(), countable);
}

bool Block::addToGrid(Grid* g) {
	vector<Cell*> addresses;
	for (auto& cell: cells) addresses.emplace_back(&cell);	
	bool result = g->addCells(addresses);
	if (result) grid = g;
	return result;
}

int Block::getPoints() const {
	for (const auto& cell: cells)
		if (cell.isValid()) return 0;
	return points;
}
