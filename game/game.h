#ifndef __GAME_H__
#define __GAME_H__
//#include "../graphics/window.h"
#include <vector>
#include "../player/player.h"
#include "../common/enums.h"
#include "../block/block.h"

class Player;

class Game {
	const std::string name;
//	Xwindow *window;
	const std::string scriptFile;
	int seed = 893;
	int startLevel = 0;
	std::vector<Player> players;
	public:
	Game();
	~Game();
	void initialize(int startLevel = 0, int seed = 893, bool isTextDisplay = false);
	void play();
	void restart();
	void print();
	void setEffect(Player&, Effect, Block::Type force = Block::Type::T);
	unsigned int addPlayer(const std::string&, const std::string&);
};

#endif
