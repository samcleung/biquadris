#include "level0.h"

using namespace std;
Level0::Level0(ifstream & infile): infile{infile} {
	char c;
	while(infile >> c)
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


