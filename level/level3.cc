#include "level3.h"
#include "../block/iblock.h"
#include "../block/jblock.h"
#include "../block/sblock.h"
#include "../block/lblock.h"
#include "../block/tblock.h"
#include "../block/zblock.h"
#include "../block/oblock.h"
#include <fstream>
#include <iostream>
using namespace std;
Level3::Level3(int seed): seed{seed}{
}

Level3::Level3(string s): readingFromScript{true}{
	srand(seed);
	char a;
	ifstream ifs(s, ifstream::in);
	while (ifs >> a)
		blocksFromFile.push_back(a);

}
vector<Block> Level3::createBlock(bool isHeavy, int numberOfTurns){
	unsigned int dropByCopy = dropBy;
	if(isHeavy)
		dropByCopy++;
	vector<Block> placeholder;
	if(readingFromScript){
	switch(blocksFromFile[position]){
		case 'I':
			placeholder.push_back(IBlock{score, dropByCopy});
		break;
		case 'J':
			placeholder.push_back(JBlock{score, dropByCopy});
		break;
		case 'L':
			placeholder.push_back(LBlock{score, dropByCopy});
		break;
		case 'O':
			placeholder.push_back(OBlock{score, dropByCopy});
		break;
		case 'S':
			placeholder.push_back(SBlock{score, dropByCopy});
		break;
		case 'T':
			placeholder.push_back(TBlock{score, dropByCopy});
		break;
		case 'Z':
			placeholder.push_back(ZBlock{score, dropByCopy});
		break;
	}
	if((unsigned)++position == blocksFromFile.size())
		position = 0;
	cout << "Size of placeholder" << placeholder.size() << endl;
	return placeholder;
//	cout << dropByCopy << endl;
	}
	

	int x = rand() % 9 + 1;
	if(x <= 1)
		placeholder.push_back(OBlock{score, dropByCopy});
	else if (x <= 2)
		placeholder.push_back(LBlock{score, dropByCopy});
	else if (x <= 3)
		placeholder.push_back(IBlock{score, dropByCopy});
	else if (x <= 4)
		placeholder.push_back(JBlock{score, dropByCopy});
	else if (x <= 5)
		placeholder.push_back(TBlock{score, dropByCopy});
	else if (x <= 7)
		placeholder.push_back(SBlock{score, dropByCopy});
	else if (x <= 9)
		placeholder.push_back(ZBlock{score, dropByCopy});
//	cout << "VALUE OF DROPBY: " << dropByCopy << endl;	
//	cout << "LENGTH OF ARRAY RETURNED" << placeholder.size() << endl;
//	cout << "VALUE OF X: " << x << endl;
	return placeholder;
}



