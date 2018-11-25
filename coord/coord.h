#ifndef __COORD_H__
#define __COORD_H__

struct Coord {
	// important coordinates
	static Coord origin() { return {0, 0}; };
	static Coord blockStart() { return {0, 14}; };
	
	unsigned int x;
	unsigned int y;
};

#endif
