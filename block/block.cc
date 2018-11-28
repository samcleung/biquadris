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

Block::Block(int points, unsigned int dropBy, unsigned int size) : points{points}, dropBy{dropBy}, size{size} {}

Block::Block(const Block& other) : points{other.points}, dropBy{other.dropBy}, size{other.size}, grid{other.grid} {
	for (const auto& cell: other.cells) cells.emplace_back(Cell{cell, this});
}

vector<Coord> Block::getCellCoords() {
	vector<Coord> coords;
	for (const auto& cell: cells) {
		if (cell.isValid()) coords.emplace_back(cell.getCoord());
	}
	return coords;
	//return move(coords);
}

bool Block::rotate(Block::Rotation r) {
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
	//return grid->moveCells(getCellCoords(), move(newCoords));
}


bool Block::translate(Block::Translation t) {
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
		//newCoords.emplace_back(move(coord));
	}
	
	return grid->moveCells(getCellCoords(), newCoords);
	//return grid->moveCells(getCellCoords(), move(newCoords));
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
	grid->drop(getCellCoords());
}

bool Block::addToGrid(Grid* g) {
	vector<Cell*> addresses;
	for (auto& cell: cells) addresses.emplace_back(&cell);	
	grid = g;
	return grid->addCells(addresses);
}

int Block::getPoints() const {
	for (const auto& cell: cells)
		if (cell.isValid()) return 0;
	return points;
}
