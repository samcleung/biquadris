#ifndef __COORD_H__
#define __COORD_H__

struct Coord {
	// important coordinates
	static Coord mid(){ return {5, 14}; };
	static Coord origin() { return {0, 0}; };
	static Coord blockStart() { return {0, 14}; };

	bool operator==(const Coord&) const;
	
	unsigned int x;
	unsigned int y;
};

#endif
