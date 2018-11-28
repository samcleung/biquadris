#include "level.h"
#include "level1.h"
#include "level0.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
using namespace std;
Level * Level::getLevel(int level, int seed) {
    switch (level) {
        case 0: throw;
        case 1: return new Level1(seed);
        case 2: return new Level2(seed);
        case 3: return new Level3(seed);
        case 4: return new Level4(seed);
        default: throw;
    }
}
Level::~Level(){}
Level * Level::getLevel(int level, std::ifstream &stream){
	return new Level0(stream);
}
Level::Level(){}
