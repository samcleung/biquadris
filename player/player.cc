#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "player.h"
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
name{name}, scriptFile{scriptfile}, game{game}, grid{new Grid(width,height)}, lev{0},
level{Level::getLevel(Level, seed, scriptfile)}, dropsSinceClear{0} {
    current = grid->addBlocks(level->createBlock(false,0));
} 

// Read in all the commands
int Player::turn() {
//    bool readFile = false;
    istream *in = &cin;
    int commandIndex;
    string command;
    string file;
    vector<string> commands {"left", "right", "up", "down", "clockwise", "counterclockwise",
                            "drop", "levelup", "leveldown", "I", "J", "L", "O", "S",
                             "Z", "T", "norandom", "random", "sequence", "restart", "force"};
    vector<int> indices;
    
    // Read input
    // Invariant that only drop/restart/EOF will end a player's turn
    while (true) {
//        if (readFile) { // Start reading from file
//            in = new ifstream(file.c_str());
//            readFile = false;
//        }
//        
        *in >> command;
//        if (file.empty() && in->eof()) { // Reached EOF in stdin
//            break;
//        }
//        if (!file.empty() && in->eof()) { // EOF in file
//            file = "";
//            delete in;
//            in = &cin; // Reset to stdin
//            *in >> command;
//        }
        
        int index = 0;
        int multiplier = 1;
        int size = command.size();
        
        // Extract multiplier from the command
        for (int i = 0; i < size; ++i) {
            if (!((command.at(i) >= '0') && (command.at(i) <= '9'))) {
                index = i;
                break;
            }
        }
        
        if (index == 0) {
            // No multiplier
            multiplier = 1;
        } else {
            multiplier = stoi(command.substr(0,index));
        }
        string call = command.substr(index);
        commandIndex = -1;

        int callSize = call.size();
        for (int j = 1; j < callSize+1; ++j) {
            int k = 0;
            for (auto &c: commands) {
                int cSize = c.size();
                if (call == c) {
                    commandIndex = k;
                    break;
                } else if ((callSize <= cSize) && (call == c.substr(0,j))) {
                    indices.emplace_back(k);
                }
                k++;
            }
            if (commandIndex != -1) {
                indices.clear(); // Found the command character for character
                break;
            } else if (indices.size() == 1) {
                commandIndex = indices.at(0); // One match for command
                indices.clear();
                break;
            }
            indices.clear(); // More than one match for command, use next letter
        }
        
        // Finished reading in command
        if (commandIndex != -1) {
            cout << commands.at(commandIndex) << endl;
            // It was a valid command
            // Check commands that do require multipliers first
            if ((commandIndex >= 0) && (commandIndex <= 8)) {
                    switch (commandIndex) {
                        case 0: { // left
                            current->translate(Block::Translation::Left, multiplier);
                            game->print();
                            break;
                        } case 1: { // right
                            current->translate(Block::Translation::Right, multiplier);
                            game->print();
                            break;
                        } case 2: { // up
                            current->translate(Block::Translation::Up, multiplier);
                            game->print();
                            break;
                        } case 3: { // down
                            current->translate(Block::Translation::Down, multiplier);
                            game->print();
                            break;
                        } case 4: { // cw
                            current->rotate(Block::Rotation::Clockwise, multiplier);
                            game->print();
                            break;
                        } case 5: { // ccw
                            current->rotate(Block::Rotation::CounterClockwise, multiplier);
                            game->print();
                            break;
                        }  case 6: { // drop
                            current->drop();
                            current = grid->addBlocks(level->createBlock(this->isHeavy(),0)); // turns after...
                            game->print();
                            break;
                        } case 7: { // level up
                            if (lev < 4) {
                                delete level;
                                ++lev;
                                if (lev == 0) {
                                    level = Level::getLevel(lev,scriptFile);
                                } else {
                                    level = Level::getLevel(lev);
                                }
                            }
                            break;
                        } case 8: { // level down
                            if (lev > 0) {
                                delete level;
                                --lev;
                                if (lev == 0) {
                                    level = Level::getLevel(lev,scriptFile);
                                } else {
                                    level = Level::getLevel(lev);
                                }
                            }
                            break;
                        }
                    }
            } else { // Commands with no multiplier
                 int points = pow(lev + 1, 2);
                 switch (commandIndex) {
                    case 9: { // I-block, change current block to this
                        current = grid->addBlock(IBlock{points,this->getDropBy()});
                        game->print();
                        break;
                    } case 10: { // J-block
                        current = grid->addBlock(JBlock{points,this->getDropBy()});
                        game->print();
                        break;
                    } case 11: { // L-block
                        current = grid->addBlock(LBlock{points,this->getDropBy()});
                        game->print();
                        break;
                    } case 12: { // O-block
                        current = grid->addBlock(OBlock{points,this->getDropBy()});
                        game->print();
                        break;
                    } case 13: { // S-block
                        current = grid->addBlock(SBlock{points,this->getDropBy()});
                        game->print();
                        break;
                    } case 14: { // Z-block
                        current = grid->addBlock(ZBlock{points,this->getDropBy()});
                        game->print();
                        break;
                    } case 15: { // T-block
                        current = grid->addBlock(TBlock{points,this->getDropBy()});
                        game->print();
                        break;
                    } case 16: { // norandom
//                        cin >> file;
                        //////////// TODO
                    } case 17: { // random
                        //////////// TODO
                    } case 18: { // sequence
//                        cin >> file;
//                        readFile = true;
                        break;
                    } case 19: { // restart the game
                        break;
                    } case 20: { // force
                        // read a char
                        break;
                    }
                }
            }
        }
        
        // End turn if drop/restart
        if ((commandIndex == 6) || (commandIndex == 19)) {
            break;
        }
        
    }
    
    if (commandIndex == 19) { // Restart the game
        return 1;
    } else if (cin.eof()) { // EOF means terminate game
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
			case 1: cout << "Level:    ";
				break;
			case 2: cout << "Score:    ";
				break;
			case 3: cout << "-----------";
		}
	}
	else if ( n <= 21)
		grid->print(abs(n-21));
	else{
		switch(n){
			case 21:
			cout << "------------------------" << endl;
			break;
			case 22: 
			cout <<" Next:      ";
			break;
			case 23: break;
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
//    current.pop_front();
//    current.push_front(block);
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
