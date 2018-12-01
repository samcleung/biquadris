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

class Game;

class Player {
	std::string name;
	std::string scriptFile;
	Effect effect = Effect::None;
	unsigned int score = 0;
    Game *game;
    Grid *grid;
    int lev;
    Level* level;
    Block *current;
    int dropsSinceClear;
	
	public:
	Player(const std::string&, const std::string&, Game *game);	
	int turn();
	void print(int);
	void setEffect(Effect, Block::Type force = Block::Type::T);
    const std::string getName();
    void setBlock(Block);
    void reset();
    bool isHeavy();
    unsigned int getDropBy();
};

#endif
