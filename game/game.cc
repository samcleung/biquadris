#include <string>
#include "game.h"
#include "../player/player.h"

using namespace std;

// grid constants
const int width = 11;
const int height = 18;

void Game::setSeed(int seed) {
	seed = seed;
	isSeeded = true;
}

void Game::setStartLevel(int level) {
	startLevel = level;
}

unsigned int Game::addPlayer(const string& playerName, const string& scriptFile) {
	//players.push_back(Player{playerName, scriptFile});
    Player player{playerName, scriptFile};
	return players.size();
}

void Game::play() {
	// todo
}

void Game::setEffect(Player& player, Effect effect) {
    player.setEffect(effect);
}

void Game::print() {
    for (int i = 0; i< height; ++i) {
        for (auto &p: players) {
            p.print(i);
        }
    }
}

//	void restart();
//	bool loadHighScore();
//	bool saveHighScore();