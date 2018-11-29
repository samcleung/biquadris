#include <string>
#include "game.h"
#include "../player/player.h"
#include <iostream>

using namespace std;

// grid constants
const int height = 18;

void Game::setSeed(int seed) {
	seed = seed;
	isSeeded = true;
}

void Game::setStartLevel(int level) {
	startLevel = level;
}

unsigned int Game::addPlayer(const string& playerName, const string& scriptFile) {
	players.emplace_back(Player{playerName, scriptFile});
//    Player player{playerName, scriptFile};
//    for (int i = height - 1; i >= 0; --i) {
//        player.print(i);
//        cout << endl;
//    }
//    cout << "working" << endl;
//    players.push_back(player);
	return players.size();
}

void Game::play() {
	// todo
}

void Game::setEffect(Player& player, Effect effect) {
    player.setEffect(effect);
}

void Game::print() {
    for (int i = height - 1; i >= 0; --i) {
        for (auto &p: players) {
            p.print(i);
        }
        cout << endl;
    }
}

//	void restart();
//	bool loadHighScore();
//	bool saveHighScore();
