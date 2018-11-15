#include <string>
#include "game.h"

using namespace std;

void Game::setSeed(int seed) {
	seed = int seed;
	isSeeded = true;
}

void Game::setStartLevel(int level) {
	startLevel = level;
}

unsigned int Game::addPlayer(const string& playerName, const string& scriptFile) {
	players.push({ playerName, scriptFile });
	return players.size();
}

// todo rest
