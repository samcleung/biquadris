#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <vector>
#include <iostream>
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
    int seed;
    Game *game;
    Grid *grid;
    int lev;
    Level* level;
    Block *current;
    int dropsSinceClear;
    std::vector<Block> queue;
    Grid *nextGrid;
	
	public:
    static std::istream *in;
    static std::string file;
	Player(const std::string&, Game *game, int level = 0, std::string scriptfile = "sequence1.txt", int seed = 893);	
	StatusCode turn();
	void print(int);
	void setEffect(Effect, Block::Type force = Block::Type::T);
	unsigned int getScore();
    const std::string getName();
    void setBlock(Block);
    void reset();
    bool isHeavy();
    unsigned int getDropBy();
    void updateDropsSinceClear();
    void clear();
};

#endif
