#ifndef __GAME_H__
#define __GAME_H__
#include <vector>
#include "../player/player.h"
#include "../common/enums.h"
#include "../block/block.h"
class Player;

class Game {
	const std::string name;
	const std::string scriptFile;
	std::vector<Player> players;
	public:
	Game();
	void initialize(int startLevel = 0, int seed = 893, bool isTextDisplay = false);
	void play();
	void restart();
	void print();
<<<<<<< HEAD
	void setEffect(Player&, Effect);
	bool loadHighScore();
	bool saveHighScore();
=======
	void setEffect(Player&, Effect, Block::Type force = Block::Type::T);
>>>>>>> master
	unsigned int addPlayer(const std::string&, const std::string&);
};

#endif
