#ifndef __LEVEL3_H__
#define __LEVEL3_H__
#include <vector>
#include "level.h"

class Level3 : public Level{
public:
	std::vector <Block> createBlock() override;
	Level3(int seed); 
};

#endif
