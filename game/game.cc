#include <string>
#include "game.h"
#include "../player/player.h"

using namespace std;
void Game::initialize(int startLevel, int seed, bool isText){}
Game::Game(){}
unsigned int Game::addPlayer(const string& playerName, const string& scriptFile) {
	players.emplace_back(Player{playerName, scriptFile});
	return players.size();
}

void Game::play() {
	while(didAnyOneLose){
		for (unsigned int i = 0 ; i < players.size(); i++){
			players[i].turn();
		}
	}
}

// todo rest
