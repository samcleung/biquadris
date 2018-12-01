#include <string>
#include <iostream>
#include "game.h"
#include "../common/enums.h"
#include "../player/player.h"
using namespace std;

// grid constants
const int height = 18;

void Game::initialize(int startLevel, int seed, bool isText){}

Game::Game(){}

unsigned int Game::addPlayer(const string& playerName, const string& scriptFile) {
	players.emplace_back(Player{playerName, scriptFile});
	return players.size();
}

void Game::play() {
    bool endTurn = false;
    
    while (!endTurn) {
        for (auto &p: players) {
           // auto result = p.turn();
	   auto result = StatusCode::Default;
	   p.turn();
            if (result == StatusCode::Default) { // Continue playing
            } else if ((result == StatusCode::Restart) || (result == StatusCode::Terminate)) { // End turns
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

void Game::setEffect(Player& player, Effect effect) {
    for (auto &p: players){
    	if(p.getName() != player.getName())
		p.setEffect(effect);
    }
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

void Game::print() {
    for (int i = height - 1; i >= 0; --i) {
        for (auto &p: players) {
            p.print(i);
	    cout << "       ";
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

