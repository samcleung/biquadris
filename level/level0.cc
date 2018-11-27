#include "level0.h"

using namespace std;
Level0::Level0(int seed, ifstream & infile): infile{infile} {}

vector <Block *> Level0::createBlock(){
	char nextBlock;
	infile >> nextBlock;
	vector <Block *> placeholder;
	switch(nextBlock){
		case 'I':
		break;
		case 'J':
		break;
		case 'L':
		break;
		case '0':
		break;
		case 'S':
		break;
		case 'T':
		break;
		case 'Z':
		break;
	}
	return placeholder;
}


