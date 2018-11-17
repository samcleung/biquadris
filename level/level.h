#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>

class Level {
	Vector <Block *> createBlock() = 0;
public:
	Level();
	~Level();
};

#endif
