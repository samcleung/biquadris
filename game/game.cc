#include <string>
#include <iostream>
#include "game.h"
#include "../player/player.h"

using namespace std;

// grid constants
const int height = 18;

void Game::initialize(int startLevel, int seed, bool isText){
	this->seed = seed;
	this->startLevel = startLevel;
	if(!isText){
		//Xwindow *window = new Xwindow();
		//this->window = window; 
	}

}

Game::Game(){

//	Xwindow *window = new Xwindow();
//	this->window = window; 
}

unsigned int Game::addPlayer(const string& playerName, const string& scriptFile) {
	players.emplace_back(Player{playerName, this, startLevel, scriptFile, seed});
	return players.size();
}

void Game::play() {
    this->print();
    
    bool endTurn = false;
    
    while (!endTurn) {
        for (auto &p: players) {
	    auto result = p.turn();
            
            if (result == StatusCode::Default) { // Continue playing
            }
	    else if (result == StatusCode::Restart) { // End turns
                endTurn = true;
                break;
            }
	    else if(result == StatusCode::Terminate){
            for (auto &q: players) {
                q.clear(); // Tell player to free all heap allocated objects
            }
	    	exit(0);
	    }
	if(highScore < p.getScore())
		highScore = p.getScore();
        }
    }
    for(auto &p: players)
    	p.reset();

	this->play();
}

void Game::setEffect(Player& player, Effect effect, Block::Type t) {
    for (auto &p: players){
    	if(p.getName() != player.getName())
		p.setEffect(effect, t);
    }
}
void Game::print() {
    cout << endl;
    for (int i = 1; i <= height + 7; i++) {
        for (auto &p: players) {
            p.print(i);
	   cout << "    ";
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

