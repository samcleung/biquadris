#include "level4.h"
#include "../block/iblock.h"
#include "../block/jblock.h"
#include "../block/sblock.h"
#include "../block/lblock.h"
#include "../block/tblock.h"
#include "../block/zblock.h"
#include "../block/oblock.h"
using namespace std;
Level4::Level4(int seed): seed{seed}{
}
vector<Block> Level4::createBlock(){
	srand(seed);
	vector<Block> placeholder;
	int x = rand() % 9 + 1;
	if(x <= 1)
		placeholder.push_back(OBlock{score, dropBy});
	else if (x <= 2)
		placeholder.push_back(LBlock{score, dropBy});
	else if (x <= 3)
		placeholder.push_back(IBlock{score, dropBy});
	else if (x <= 4)
		placeholder.push_back(JBlock{score, dropBy});
	else if (x <= 5)
		placeholder.push_back(TBlock{score, dropBy});
	else if (x <= 7)
		placeholder.push_back(SBlock{score, dropBy});
	else if (x <= 9)
		placeholder.push_back(ZBlock{score, dropBy});
	return placeholder;
}
