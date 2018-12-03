#include "level4.h"
#include "../block/iblock.h"
#include "../block/jblock.h"
#include "../block/sblock.h"
#include "../block/starblock.h"
#include "../block/lblock.h"
#include "../block/tblock.h"
#include "../block/zblock.h"
#include "../block/oblock.h"
#include "../coord/coord.h"
#include <vector>
#include <fstream>
using namespace std;
Level4::Level4(int seed): seed{seed}{
}
Level4::Level4(string s): isFromFile{true}{
	srand(seed);
	char a;
	ifstream ifs(s, ifstream::in);
	while (ifs >> a)
		readFromFile.push_back(a);
}
vector<Block> Level4::createBlockIMP(bool isHeavy, int numberOfTurns){
	int dropByCopy = dropBy;
	if(isHeavy)
		dropBy++;
	vector<Block> placeholder;
	if(numberOfTurns % 5 == 0 && numberOfTurns > 0){
		placeholder.push_back(StarBlock{0, dropBy, Coord::mid()});
	}
	if(isFromFile){
	switch(readFromFile[position]){
		case 'I':
			placeholder.push_back(IBlock{score, dropBy});
		break;
		case 'J':
			placeholder.push_back(JBlock{score, dropBy});
		break;
		case 'L':
			placeholder.push_back(LBlock{score, dropBy});
		break;
		case 'O':
			placeholder.push_back(OBlock{score, dropBy});
		break;
		case 'S':
			placeholder.push_back(SBlock{score, dropBy});
		break;
		case 'T':
			placeholder.push_back(TBlock{score, dropBy});
		break;
		case 'Z':
			placeholder.push_back(ZBlock{score, dropBy});
		break;
	}
	if((unsigned)++position == readFromFile.size())
		position = 0;
	}
	else{
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
	}
//	cout << "VALUE OF NUMBER OF TURNS" << numberOfTurns << endl;
//	cout << "LENGTH OF ARRAY RETURNED" << placeholder.size() << endl;
	dropBy = dropByCopy;
	return placeholder;
}
