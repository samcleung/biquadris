#include <string>
#include <iostream>
#include "game.h"
#include "../player/player.h"

using namespace std;

// grid constants
const int height = 18;

void Game::initialize(int startLevel, int seed, bool isText){}

Game::Game(){}

unsigned int Game::addPlayer(const string& playerName, const string& scriptFile) {
	players.emplace_back(Player{playerName, this, startLevel, scriptFile, seed});
	return players.size();
}

void Game::play() {
    this->print();
    
    bool endTurn = false;
    int result;
    
    while (!endTurn) {
        for (auto &p: players) {
            result = p.turn();
            
            if (result == 0) { // Continue playing
            } else if ((result == 1) || (result == 2)) { // End turns
                endTurn = true;
                break;
            }
        
	//if(highScore < p.getScore())
//		highScore = p.getScore()
  //      }
	}
    }
    
    // if result is 2 the game terminates, either EOF or game over
}

void Game::setEffect(Player& player, Effect effect, Block::Type t) {
    for (auto &p: players){
    	if(p.getName() != player.getName())
		p.setEffect(effect, t);
    }
}
void Game::print() {
    for (int i = 1; i <= height + 6; i++) {
        for (auto &p: players) {
            p.print(i);
        }
        cout << endl;
    }
}

void Game::restart() {
    for (auto &p: players) {
        p.reset();
    }
    this->play();
}

