#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <list>
#include "../game/game.h"
#include "../grid/grid.h"
#include "../level/level.h"
#include "../block/block.h"
#include "../coord/coord.h"
#include "../common/enums.h"

class Player {
	std::string name;
	std::string scriptFile;
	Effect effect = Effect::None;
	unsigned int score = 0;
    Grid *grid;
    int lev;
    Level* level;
    Block *current;
    int dropsSinceClear;
	
	public:
	Player(const std::string&, const std::string&);	
	int turn();
	void print(int);
	void setEffect(Effect);
    const std::string getName();
    void setBlock(Block);
    void reset();
};

#endif
