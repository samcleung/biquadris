#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "player.h"
#include "../command/command.h"
#include "../block/iblock.h"
#include "../block/jblock.h"
#include "../block/lblock.h"
#include "../block/oblock.h"
#include "../block/sblock.h"
#include "../block/zblock.h"
#include "../block/tblock.h"
#include "../level/level.h"

using namespace std;

// grid constants
const int width = 11;
const int height = 18;

Player::Player(const std::string& name, Game *game, int Level,string scriptfile, int seed) :
name{name}, scriptFile{scriptfile}, game{game}, grid{new Grid(width,height)}, lev{Level},
level{Level::getLevel(Level, seed, scriptfile)}, dropsSinceClear{0} {
    current = grid->addBlocks(level->createBlock(false,0));
} 

// Read in all the commands
int Player::turn() {
//	bool readFile = false;
	istream *in = &cin;
	string input;
	string file;
	bool quit = false;

	// Read input
	// Invariant that only drop/restart/EOF will end a player's turn
	while (!quit) {
		bool validCommand = true;
//		if (readFile) { // Start reading from file
//			in = new ifstream(file.c_str());
//			readFile = false;
//		}
//        
		if (!validCommand) cout << "ERROR: Invalid command" << endl;
		cout << "Enter a command: ";
        	*in >> input;
//		if (file.empty() && in->eof()) // Reached EOF in stdin
//			break;
//
//		if (!file.empty() && in->eof()) { // EOF in file
//			file = "";
//			delete in;
//			in = &cin; // Reset to stdin
//			*in >> command;
//		}
        
		Command command{input};

		int points = pow(lev + 1, 2);
		validCommand = true;
		switch (command) {
			case (int)Command::Action::Left:
				current->translate(Block::Translation::Left, command.multiplier);
				game->print();
				break;
			case (int)Command::Action::Right:
				current->translate(Block::Translation::Right, command.multiplier);
				game->print();
				break;
			case (int)Command::Action::Down:
				current->translate(Block::Translation::Down, command.multiplier);
				game->print();
				break;
			case (int)Command::Action::Clockwise:
				current->rotate(Block::Rotation::Clockwise, command.multiplier);
				game->print();
				break;
			case (int)Command::Action::CounterClockwise:
				current->rotate(Block::Rotation::CounterClockwise, command.multiplier);
				game->print();
				break;
			case (int)Command::Action::Drop:
				current->drop();
				current = grid->addBlocks(level->createBlock(isHeavy(), 0));
				game->print();
				quit = true;
				break;
			case (int)Command::Action::LevelUp:
				if (lev < 4) {
					delete level;
					++lev;
					level = lev ? Level::getLevel(lev) : Level::getLevel(lev,scriptFile);
				}
				break;
			case (int)Command::Action::LevelDown:
				if (lev > 0) {
					delete level;
					--lev;
					level = lev ? Level::getLevel(lev) : Level::getLevel(lev,scriptFile);
				}
				break;
			case (int)Command::Action::I:
				current = grid->addBlock(IBlock{points, getDropBy()});
				game->print();
				break;
			case (int)Command::Action::J:
				current = grid->addBlock(JBlock{points, getDropBy()});
				game->print();
				break;
			case (int)Command::Action::L:
				current = grid->addBlock(LBlock{points, getDropBy()});
				game->print();
				break;
			case (int)Command::Action::O:
				current = grid->addBlock(OBlock{points, getDropBy()});
				game->print();
				break;
			case (int)Command::Action::S:
				current = grid->addBlock(SBlock{points, getDropBy()});
				game->print();
				break;
			case (int)Command::Action::Z:
				current = grid->addBlock(ZBlock{points, getDropBy()});
				game->print();
				break;
			case (int)Command::Action::T:
				current = grid->addBlock(TBlock{points, getDropBy()});
				game->print();
				break;
			case (int)Command::Action::NoRandom:
				// TODO
				//cin >> file;
				break;
			case (int)Command::Action::Random:
				// TODO
				break;
			case (int)Command::Action::Sequence:
				// TODO
				//cin >> file;
				//readFile = true;
				break;
			case (int)Command::Action::Restart:
				return 1;
				break;
			default:
				validCommand = command.execute();
		}
	}
	
	if (cin.eof()) { // EOF means terminate game
		return 2;
	} else { // End the turn normally
		return 0;
	}    ////// Force z?? Return a number from 3 to 9
	return 0;
}

// Prints a line of the player's grid
void Player::print(int n) {
	if(n <= 3){
		switch(n){
			case 1: cout << "Level:      " << lev;
				break;
			case 2: cout << "Score:      " << score;
				break;
			case 3: cout << "-------------";
		}
	}
	else if ( n <= 21)
		grid->print(abs(n-21));
	else{
		switch(n){
			case 22:
			cout << "-------------";
			break;
			case 23: 
			cout <<"Next:       ";
			break;
			case 24: break;
		}
	}

}

void Player::setEffect(Effect effect, Block::Type force) {
    this->effect = effect;
    if(effect == Effect::Force){
	switch (force) { // Uncomment later on
		case Block::Type::I: setBlock(IBlock{}); break;
		case Block::Type::J: setBlock(JBlock{}); break;
		case Block::Type::L: setBlock(LBlock{}); break;
		case Block::Type::O: setBlock(OBlock{}); break;
		case Block::Type::S: setBlock(SBlock{}); break;
		case Block::Type::T: setBlock(TBlock{}); break;
		case Block::Type::Z: setBlock(ZBlock{}); break;
        	}
	}
}

const string Player::getName() {
    return name;
}

void Player::setBlock(Block block) {
    current = grid->addBlock(block);
}

void Player::reset() {
    effect = Effect::None;
    delete grid;
    grid = new Grid{width,height};
    lev = 0;
    delete level;
    level = Level::getLevel(0,scriptFile);
    current = grid->addBlocks(level->createBlock(this->isHeavy(),lev));
    dropsSinceClear = 0;    
}

bool Player::isHeavy() {
    if (effect == Effect::Heavy) {
        return true;
    } else {
        return false;
    }
}

unsigned int Player::getDropBy() {
    if (effect == Effect::Heavy) {
        return 1;
    } else {
        return false;
    }
}

unsigned int Player::getScore(){
	return score;
}
