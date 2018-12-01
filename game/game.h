#ifndef __GAME_H__
#define __GAME_H__
#include <vector>
#include "../player/player.h"
#include "../common/enums.h"

class Player;

class Game {
	std::vector<Player> players;
	int highScore = 0;
	public:
	Game();
	void initialize(int startLevel = 0, int seed = 893, bool isTextDisplay = false);
	void play();
	void restart();
	void print();
	void setEffect(Player&, Effect);
	unsigned int addPlayer(const std::string&, const std::string&);
};

#endif
