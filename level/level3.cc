#include "level3.h"
#include "../block/iblock.h"
#include "../block/jblock.h"
#include "../block/sblock.h"
#include "../block/lblock.h"
#include "../block/tblock.h"
#include "../block/zblock.h"
#include "../block/oblock.h"
#include <fstream>
using namespace std;
Level3::Level3(int seed): seed{seed}{
}

Level3::Level3(string s): readingFromScript{true}{
	char a;
	ifstream ifs(s, ifstream::in);
	while (ifs >> a)
		blocksFromFile.push_back(a);

}
vector<Block> Level3::createBlock(bool isHeavy, int numberOfTurns){
	srand(seed);
	int dropByCopy = dropBy;
	if(isHeavy)
		dropBy++;
	vector<Block> placeholder;
	if(readingFromScript){
	switch(blocksFromFile[position]){
		case 'I':
			placeholder.push_back(IBlock{1, dropBy});
		case 'J':
			placeholder.push_back(JBlock{1, dropBy});
		break;
		case 'L':
			placeholder.push_back(LBlock{1, dropBy});
		break;
		case '0':
			placeholder.push_back(OBlock{1, dropBy});
		break;
		case 'S':
			placeholder.push_back(SBlock{1, dropBy});
		break;
		case 'T':
			placeholder.push_back(TBlock{1, dropBy});
		break;
		case 'Z':
			placeholder.push_back(ZBlock{1, dropBy});
		break;
	}
	if((unsigned)++position == blocksFromFile.size())
		position = 0;
	return placeholder;
	}
	

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
	
	dropBy = dropByCopy;
	return placeholder;
}



