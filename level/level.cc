#include <memory>
#include "level.h"
#include "level1.h"
#include "level0.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

using namespace std;

unique_ptr<Level> Level::getLevel(int level, int seed, string sequencefile) {
    switch (level) {
        case 0: return move(make_unique<Level0>(sequencefile));
        case 1: return move(make_unique<Level1>((unsigned) seed));
        case 2: return move(make_unique<Level2>((unsigned)seed));
        case 3: return move(make_unique<Level3>((unsigned)seed));
        case 4: return move(make_unique<Level4>((unsigned)seed));
        default: throw;
    }
}

vector<Block> Level::createBlock(bool isHeavy, int numberOfTurns){
	return createBlockIMP(isHeavy, numberOfTurns);
}

Level::~Level(){}

unique_ptr<Level> Level::getLevel(int level, string stream){
	switch(level){
	case 0:
		return move(make_unique<Level0>(stream));
	case 3:
		return move(make_unique<Level3>(stream));
	case 4:
		return move(make_unique<Level4>(stream));
	}
	return move(make_unique<Level4>(stream));
}

Level::Level(){}
