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
}
vector<Block> Level2::createBlock(){
	srand(seed);
	vector<Block> placeholder;
	int x = rand() % 7 + 1;
	if(x <= 1)
		placeholder.push_back(SBlock{score,0});
	else if (x <= 2)
		placeholder.push_back(ZBlock{score,0});
	else if (x <= 3)
		placeholder.push_back(IBlock{score,0});
	else if (x <= 4)
		placeholder.push_back(JBlock{score,0});
	else if (x <= 5)
		placeholder.push_back(TBlock{score,0});
	else if (x <= 6)
		placeholder.push_back(OBlock{score,0});
	else if (x <= 7)
		placeholder.push_back(LBlock{score,0});

	return placeholder;
}


