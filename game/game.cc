#include <string>
#include "game.h"
#include "../player/player.h"

using namespace std;
void Game::initialize(int startLevel, int seed, bool isText){}

unsigned int Game::addPlayer(const string& playerName, const string& scriptFile) {
	players.emplace_back(Player{playerName, scriptFile});
	return players.size();
}

void Game::play() {
	// todo
}

// todo rest
