#include "level.h"
#include "level1.h"
#include "level0.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
using namespace std;
Level * Level::getLevel(int level, int seed, string sequencefile) {
    switch (level) {
        case 0: return new Level0(sequencefile);
        case 1: return new Level1((unsigned)seed);
        case 2: return new Level2((unsigned)seed);
        case 3: return new Level3((unsigned)seed);
        case 4: return new Level4((unsigned)seed);
        default: throw;
    }
}
Level::~Level(){}
Level * Level::getLevel(int level, string stream){
	return new Level0(stream);
}
Level::Level(){}
