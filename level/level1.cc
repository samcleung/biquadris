#include "level1.h"
#include <cstdlib>
#include "../block/iblock.h"
#include "../block/jblock.h"
#include "../block/sblock.h"
#include "../block/lblock.h"
#include "../block/tblock.h"
#include "../block/zblock.h"
#include "../block/oblock.h"
#include <iostream>

using namespace std;

Level1::Level1(unsigned int seed): seed{seed}{
	srand(seed);
}
vector<Block> Level1::createBlock(bool isHeavy, int numberOfTurns){
	unsigned int dropBy = 0;
	if(isHeavy)
		dropBy++;
	vector<Block> placeholder;

	int x = rand() % 12 + 1;
	cout << x << endl;
	if(x <= 1)
		placeholder.push_back(SBlock{score,dropBy});
	else if (x <= 2)
		placeholder.push_back(ZBlock{score,dropBy});
	else if (x <= 4)
		placeholder.push_back(IBlock{score,dropBy});
	else if (x <= 6)
		placeholder.push_back(JBlock{score,dropBy});
	else if (x <= 8)
		placeholder.push_back(TBlock{score,dropBy});
	else if (x <= 10)
		placeholder.push_back(OBlock{score,dropBy});
	else if (x <= 12)
		placeholder.push_back(LBlock{score,dropBy});

	cout << "VALUE OF SEED" << seed << endl;
	return placeholder;

}




