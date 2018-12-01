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
    Player test{playerName, scriptFile};
//	players.emplace_back(Player{playerName, scriptFile});
    return 0;
//	return players.size();
}

void Game::play() {
    bool endTurn = false;
    int result;
    
    while (!endTurn) {
        for (auto &p: players) {
            result = p.turn();
            
            if (result == 0) { // Continue playing
            } else if ((result == 1) || (result == 2)) { // End turns
                endTurn = true;
                break;
            } else { // Apply force on all players, number from 3 to 9 indicates block
                for (auto &q: players) {
                    if (p.getName() != q.getName()) { // Change this player's block
//                        switch (result) { // Uncomment later on
//                            case 3: q.setBlock(new IBlock()); break;
//                            case 4: q.setBlock(new JBlock()); break;
//                            case 5: q.setBlock(new LBlock()); break;
//                            case 6: q.setBlock(new OBlock()); break;
//                            case 7: q.setBlock(new SBlock()); break;
//                            case 8: q.setBlock(new TBlock()); break;
//                            case 9: q.setBlock(new ZBlock()); break;
//                        }
                    }
                }
            }
        }
    }
    
    if (result == 1) {
        this->restart();
    }
    
    // if result is 2 the game terminates, either EOF or game over
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

void Game::restart() {
    for (auto &p: players) {
        p.reset();
    }
    this->play();
}

bool Game::loadHighScore() {
    return true; ////////// When is this called
}

bool Game::saveHighScore() {
    return true;
}
