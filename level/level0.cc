#include "level0.h"
#include <fstream>
#include "../block/iblock.h"
#include "../block/jblock.h"
#include "../block/sblock.h"
#include "../block/lblock.h"
#include "../block/tblock.h"
#include "../block/zblock.h"
#include "../block/oblock.h"
using namespace std;
Level0::Level0(string infile): infile{infile} {
	char c;
	ifstream ifs(infile, ifstream::in);
	while(ifs >> c)
		commands.push_back(c);
}
vector <Block> Level0::createBlockIMP(bool isHeavy, int numberOfTurns){
	char nextBlock = commands[position];
	position++;
	unsigned int dropBy = 0;
	if(position == commands.size())
		position = 0;
	if(isHeavy)
		dropBy++;
	vector <Block> placeholder;
	switch(nextBlock){
		case 'I':
		placeholder.push_back(IBlock{1, dropBy});
		break;
		case 'J':
		placeholder.push_back(JBlock{1, dropBy});
		break;
		case 'L':
		placeholder.push_back(LBlock{1, dropBy});
		break;
		case 'O':
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
	return placeholder;
}


