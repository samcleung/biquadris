#include <string>
#include "game.h"
#include "../player/player.h"

using namespace std;

void Game::setSeed(int seed) {
	seed = seed;
	isSeeded = true;
}

void Game::setStartLevel(int level) {
	startLevel = level;
}

unsigned int Game::addPlayer(const string& playerName, const string& scriptFile) {
	players.emplace_back(Player{playerName, scriptFile});
	return players.size();
}

// todo rest
