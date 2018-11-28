#ifndef __LEVEL4_H__
#define __LEVEL4_H__
#include <vector>
#include "level.h"

class Level4: public Level{
public:
	std::vector <Block> createBlock() override;
	Level4(int seed); 
};

#endif
