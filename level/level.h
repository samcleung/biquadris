#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <Vector>

class Level {
	Vector <Block *> createBlock() = 0;
public:
	Level();
	~Level();
};

#endif
