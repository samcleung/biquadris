#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include "../game/game.h"
#include "../grid/grid.h"
#include "../level/level.h"
#include "../block/block.h"
#include "../common/enums.h"

// forward declaration, fix circular includes
class Game;

class Player {
	std::string name;
	std::string scriptFile;
	Effect effect = Effect::None;
	unsigned int score = 0;
	Game* game;
	Grid* grid;
	Level* level;
	Block* current;
	
	public:
	Player(const std::string&, const std::string&);	
	void turn();
	void print(int);
	void setEffect(Effect);
};

#endif
