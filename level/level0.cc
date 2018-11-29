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
vector <Block> Level0::createBlock(){
	char nextBlock = commands[position];
	position++;
	if(position == commands.size())
		position = 0;
	
	vector <Block> placeholder;
	switch(nextBlock){
		case 'I':
		placeholder.push_back(IBlock{1, 0});
		case 'J':
		placeholder.push_back(JBlock{1, 0});
		break;
		case 'L':
		placeholder.push_back(LBlock{1, 0});
		break;
		case '0':
		placeholder.push_back(OBlock{1, 0});
		break;
		case 'S':
		placeholder.push_back(SBlock{1, 0});
		break;
		case 'T':
		placeholder.push_back(TBlock{1, 0});
		break;
		case 'Z':
		placeholder.push_back(ZBlock{1, 0});

		break;
	}
	return placeholder;
}


