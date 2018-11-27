#include "coord.h"

bool Coord::operator==(const Coord& other) const {
	return (x == other.x && y == other.y);
}
