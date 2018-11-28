#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include <vector>
#include "level.h"

class Level2: public Level {
public:
	std::vector <Block> createBlock() override;
	Level2(int seed); 
};

#endif
