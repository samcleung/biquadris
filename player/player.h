#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include "../game/game.h"
#include "../grid/grid.h"
#include "../level/level.h"
#include "../block/block.h"

class Player {
	std::string name;
	std::string scriptFile;
	Game::Effect effect = Game::Effect::None;
	unsigned int score = 0;
	Game* game;
	Grid* grid;
	Level* level;
	Block* current;
	
	public:
	// add ctrs & Big 5 as needed
	void turn();
	void print(int);
	void setEffect(Game::Effect);
};

#endif
