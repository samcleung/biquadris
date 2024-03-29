#include "../block/iblock.h"
#include "../block/jblock.h"
#include "../block/sblock.h"
#include "../block/lblock.h"
#include "../block/tblock.h"
#include "../block/zblock.h"
#include "../block/oblock.h"
#include "level2.h"

using namespace std;
Level2::Level2(int seed): seed{seed}{
	srand(seed);
}
vector<Block> Level2::createBlockIMP(bool isHeavy, int numberOfTurns){
	vector<Block> placeholder;
	unsigned int dropBy = 0;
	if(isHeavy)
		dropBy++;
	int x = rand() % 7 + 1;
	if(x <= 1)
		placeholder.push_back(SBlock{score,dropBy});
	else if (x <= 2)
		placeholder.push_back(ZBlock{score,dropBy});
	else if (x <= 3)
		placeholder.push_back(IBlock{score,dropBy});
	else if (x <= 4)
		placeholder.push_back(JBlock{score,dropBy});
	else if (x <= 5)
		placeholder.push_back(TBlock{score,dropBy});
	else if (x <= 6)
		placeholder.push_back(OBlock{score,dropBy});
	else if (x <= 7)
		placeholder.push_back(LBlock{score,dropBy});

	return placeholder;
}


