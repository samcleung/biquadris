#ifndef __GAME_H__
#define __GAME_H__

class Game {
	const std::string name;
	const std::string scriptFile;
	vector<Player> players;
	int seed;
	bool isSeeded = false;
	
	public:
	bool isTextOnly = false;

	enum Effect { None, Blind, Force, Heavy };
	void restart();
	void print();
	void setEffect(Player&, Effect);
	bool loadHighScore();
	bool saveHighScore();
	void setSeed(int);
	unsigned int addPlayer(const std::string&, const std::string);
	void setStartLevel(int level);
};

#endif
