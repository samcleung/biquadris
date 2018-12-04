#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <utility>
#include <memory>
#include "player.h"
#include "../common/enums.h"
#include "../command/command.h"
#include "../block/iblock.h"
#include "../block/jblock.h"
#include "../block/lblock.h"
#include "../block/oblock.h"
#include "../block/sblock.h"
#include "../block/zblock.h"
#include "../block/tblock.h"
#include "../level/level.h"
#include "../coord/coord.h"

using namespace std;

// grid constants
const int width = 11;
const int height = 18;
const int nextHeight = 2;

istream *Player::in = &cin;
string Player::file = "";

Player::Player(const std::string& name, Game *game, int Level, string scriptfile, int seed) :
name{name}, scriptFile{scriptfile}, seed{seed}, game{game}, grid{make_unique<Grid>(width, height)}, initLevel{Level}, lev{Level}, level{Level::getLevel(Level, seed, scriptfile)}, nextGrid{make_unique<Grid>(width, nextHeight)} {
	current = grid->addBlocks(level->createBlock(isHeavy(),0));
	update();
	queue = level->createBlock(isHeavy(),1);
	nextGrid->addBlock({Block{queue.back(), Coord::origin()}});
} 

// Read in all the commands
StatusCode Player::turn() {
	string input;
	string levelFile;
	bool validCommand = true;
	bool quit = false;

	// Read input
	// Invariant that only drop/restart/EOF will end a player's turn
	while (!quit) {
		if (!validCommand) {
			Command::promptInvalid();
			validCommand = true;
		}

        if (in == &cin) Command::prompt(name);
        *in >> input;
        
		if (file.empty() && in->eof()) // Reached EOF in stdin
			break;

		if (!file.empty() && in->eof()) { // EOF in file
			file = "";
			delete in;
			in = &cin; // Reset to stdin
			Command::prompt(name);
			*in >> input;
		}
        
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
			case (int)Command::Action::Drop: {
				current->drop();
				update();
				// Get next block in queue
				current = grid->addBlocks(queue);
				update();
				queue = level->createBlock(isHeavy(), grid->getDropsSinceClear());
				nextGrid = make_unique<Grid>(width, nextHeight);
				nextGrid->addBlock({Block{queue.back(),Coord::origin()}});
				if (!current) return StatusCode::Terminate;
				game->print();
				effect = Effect::None;
				quit = true;
				break;
			}
			case (int)Command::Action::LevelUp:
				for(unsigned int i = 0; i < command.multiplier; ++i) {
				if (lev < 4) {
					++lev;
					level = unique_ptr<Level>(lev ? Level::getLevel(lev) : Level::getLevel(lev,scriptFile));
					}
				}
				game->print();
				break;
			case (int)Command::Action::LevelDown:
				for(unsigned int i = 0; i < command.multiplier; ++i) {
					if (lev > 0) {
						--lev;
						level = unique_ptr<Level>(lev ? Level::getLevel(lev) : Level::getLevel(lev, scriptFile));
					}
				}
				game->print();
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
				*in >> levelFile;
				if ((lev == 3) || (lev == 4)) {
					level = unique_ptr<Level>(Level::getLevel(lev, levelFile));
				}
				break;
			case (int)Command::Action::Random:
				if ((lev == 3) || (lev == 4)) {
					level = unique_ptr<Level>(Level::getLevel(lev, seed, scriptFile));
				}
				break;
			case (int)Command::Action::Sequence:
				*in >> file;
				in = new ifstream(file.c_str());
				break;
			case (int)Command::Action::Restart:
				return StatusCode::Restart;
				break;
			default:
				validCommand = command();
		}
	}
	
	if (in->eof()) { // EOF means terminate game
		cout << endl;
		return StatusCode::Terminate;
	} else { // End the turn normally
		return StatusCode::Default;
	}
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
	else if (n <= 21) {
		grid->print(abs(n - 21), effect);
	} else {
		switch(n){
			case 22:
                cout << "-------------";
                break;
			case 23: 
                cout << "Next:        ";
                break;
			case 24:
					nextGrid->print(1, Effect::None);
					break;
			case 25:
					nextGrid->print(0, Effect::None);
					break;
		}
	}
}

void Player::setEffect(Effect effect, Block::Type force) {
	this->effect = effect;
	if(effect == Effect::Force){
		int points = pow(lev + 1, 2);
		switch (force) {
			case Block::Type::I: setBlock(IBlock{points, getDropBy()}); break;
			case Block::Type::J: setBlock(JBlock{points, getDropBy()}); break;
			case Block::Type::L: setBlock(LBlock{points, getDropBy()}); break;
			case Block::Type::O: setBlock(OBlock{points, getDropBy()}); break;
				case Block::Type::S: setBlock(SBlock{points, getDropBy()}); break;
			case Block::Type::T: setBlock(TBlock{points, getDropBy()}); break;
				case Block::Type::Z: setBlock(ZBlock{points, getDropBy()}); break;
			case Block::Type::None: break;
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
	grid = make_unique<Grid>(width,height);
	lev = initLevel;
	level = unique_ptr<Level>(lev ? Level::getLevel(lev) : Level::getLevel(lev,scriptFile));
	score = 0;
	current = grid->addBlocks(level->createBlock(isHeavy(), 0));    
	update();
	queue = level->createBlock(isHeavy(), 0);
	nextGrid = make_unique<Grid>(width, nextHeight);
	nextGrid->addBlock({Block{queue.back(), Coord::origin()}});
}

bool Player::isHeavy() {
	return effect == Effect::Heavy;
}

unsigned int Player::getDropBy() {
	return effect == Effect::Heavy ? 1 : 0;
}

unsigned int Player::getScore() {
	return score;
}

void Player::clear() {
}

void Player::readEffect(int e) {
    bool validEffect = true;
    string eff;
    if (e >= 2) {
        while(validEffect) {
            if (!file.empty() && in->eof()) { // EOF in file
                file = "";
                delete in;
                in = &cin; // Reset to stdin
            }
            if (in == &cin) {
                cout << "Please enter an effect (blind, heavy, or force): ";
            }
            *in >> eff;
            if (eff == "blind") {
                validEffect = false;
                game->setEffect(*this, Effect::Blind, Block::Type::None);
            } else if (eff == "heavy") {
                validEffect = false;
                game->setEffect(*this, Effect::Heavy, Block::Type::None);
            } else if (eff == "force") {
                bool readChar = true;;
                validEffect = false;
                char c;
                while(readChar) {
                    if (!file.empty() && in->eof()) { // EOF in file
                        file = "";
                        delete in;
                        in = &cin; // Reset to stdin
                    }
                    readChar = false;
                    if (in == &cin) {
                        cout << "Please enter a block type: ";
                    }
                    *in >> c;
                    switch (c) {
                        case 'I': game->setEffect(*this, Effect::Force, Block::Type::I); break;
                        case 'J': game->setEffect(*this, Effect::Force, Block::Type::J); break;
                        case 'L': game->setEffect(*this, Effect::Force, Block::Type::L); break;
                        case 'O': game->setEffect(*this, Effect::Force, Block::Type::O); break;
                        case 'S': game->setEffect(*this, Effect::Force, Block::Type::S); break;
                        case 'T': game->setEffect(*this, Effect::Force, Block::Type::T); break;
                        case 'Z': game->setEffect(*this, Effect::Force, Block::Type::Z); break;
                        default: readChar = true; break;
                    }
                }
            } else {
                if (in == &cin) {
                    cout << "Invalid effect." << endl;
                }
            }
        }
    }
}

void Player::update() {
	pair<int,int> pointRowPair{grid->update(lev)};
	score += pointRowPair.first;
	readEffect(pointRowPair.second);
}
