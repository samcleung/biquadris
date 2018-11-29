#ifndef __GAME_H__
#define __GAME_H__
#include <vector>
#include "../player/player.h"
#include "../common/enums.h"

class Player;

class Game {
	const std::string name;
	const std::string scriptFile;
	std::vector<Player> players;
	int seed;
	bool isSeeded = false;
	int startLevel = 0;
	
	public:
	bool isTextOnly = false;
	
	void play();
	void restart();
	void print();
	void setEffect(Player&, Effect);
	bool loadHighScore();
	bool saveHighScore();
	void setSeed(int);
	unsigned int addPlayer(const std::string&, const std::string&);
	void setStartLevel(int level);
};

#endif
