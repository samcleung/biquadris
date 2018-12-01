#include <iostream>
#include <fstream>
#include <vector>
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

Player::Player(const std::string& name, const std::string& scriptFile) :
name{name}, scriptFile{scriptFile} {
    //, grid{nullptr}, lev{0}, level{nullptr} 
    //, grid{make_unique<Grid>(width,height)}, lev{0}
    //    current = level->createBlock();
    //, level{Level::getLevel(0,scriptFile)}
}

// Read in all the commands
int Player::turn() {
////    bool readFile = false;
//    istream *in = &cin;
//    int commandIndex;
//    string command;
//    string file;
//    vector<string> commands {"left", "right", "up", "down", "clockwise", "counterclockwise",
//                            "drop", "levelup", "leveldown", "I", "J", "L", "O", "S",
//                             "Z", "T", "norandom", "random", "sequence", "restart", "force"};
//    vector<int> indices;
//    
//    // Read input
//    // Invariant that only drop/restart/EOF will end a player's turn
//    while (true) {
////        if (readFile) { // Start reading from file
////            in = new ifstream(file.c_str());
////            readFile = false;
////        }
////        
//        *in >> command;
////        if (file.empty() && in->eof()) { // Reached EOF in stdin
////            break;
////        }
////        if (!file.empty() && in->eof()) { // EOF in file
////            file = "";
////            delete in;
////            in = &cin; // Reset to stdin
////            *in >> command;
////        }
//        
//        int index = 0;
//        int multiplier;
//        int size = command.size();
//        
//        // Extract multiplier from the command
//        for (int i = 0; i < size; ++i) {
//            if (!((command.at(i) >= '0') && (command.at(i) <= '9'))) {
//                index = i;
//                break;
//            }
//        }
//        
//        if (index == 0) {
//            // No multiplier
//            multiplier = 1;
//        } else {
//            multiplier = stoi(command.substr(0,index));
//        }
//        string call = command.substr(index);
//        commandIndex = -1;
//
//        int callSize = call.size();
//        for (int j = 1; j < callSize+1; ++j) {
//            int k = 0;
//            for (auto &c: commands) {
//                int cSize = c.size();
//                if (call == c) {
//                    commandIndex = k;
//                    break;
//                } else if ((callSize <= cSize) && (call == c.substr(0,j))) {
//                    indices.emplace_back(k);
//                }
//                k++;
//            }
//            if (commandIndex != -1) {
//                indices.clear(); // Found the command character for character
//                break;
//            } else if (indices.size() == 1) {
//                commandIndex = indices.at(0); // One match for command
//                indices.clear();
//                break;
//            }
//            indices.clear(); // More than one match for command, use next letter
//        }
//        
//        // Finished reading in command        
//        if (commandIndex != -1) {
//            // It was a valid command
//            // Check commands that do require multipliers first
//            if ((commandIndex >= 0) && (commandIndex <= 8)) {
//                for (int i = 0; i < multiplier; ++i) {
////                    switch (commandIndex) {
////                        case 0: { // left
////                            current.front().translate(Block::Translation::Left, multiplier);
////                            break;
////                        } case 1: { // right
////                            current.front().translate(Block::Translation::Right, multiplier);
////                            break;
////                        } case 2: { // up
////                            current.front().translate(Block::Translation::Up, multiplier);
////                            break;
////                        } case 3: { // down
////                            current.front().translate(Block::Translation::Down, multiplier);
////                            break;
////                        } case 4: { // cw
////                            current.front().rotate(Block::Rotation::Clockwise, multiplier);
////                            break;
////                        } case 5: { // ccw
////                            current.front().rotate(Block::Rotation::CounterClockwise, multiplier);
////                            break;
////                        }  case 6: { // drop
////                            for (auto &v: current) {
////                                v.drop();
////                                grid->addBlock(v);
////                            }
////                            current.clear();
//////                            current = level->createBlock();
////                            break;
////                        } case 7: { // level up
////                            delete level;
////                            ++lev;
////                            if (lev == 0) {
//////                                level = Level::getLevel(lev,scriptFile);
////                            } else {
//////                                level = Level::getLevel(lev);
////                            }
////                            break;
////                        } case 8: { // level down
////                            delete level;
////                            --lev;
////                            if (lev == 0) {
//////                                level = Level::getLevel(lev,scriptFile);
////                            } else {
//////                                level = Level::getLevel(lev);
////                            }
////                            break;
////                        }
////                    }
//                }
//            } else { // Commands with no multiplier
//                 switch (commandIndex) {
//                    case 9: { // I-block, change current block to this
////                        current.at(0) = IBlock(); // Copying error
//                        break;
//                    } case 10: { // J-block
////                        current.at(0) = JBlock();
//                        break;
//                    } case 11: { // L-block
////                        current.at(0) = LBlock();
//                        break;
//                    } case 12: { // O-block
////                        current.at(0) = OBlock();
//                        break;
//                    } case 13: { // S-block
////                        current.at(0) = SBlock();
//                        break;
//                    } case 14: { // Z-block
////                        current.at(0) = ZBlock();
//                        break;
//                    } case 15: { // T-block
////                        current.at(0) = TBlock();
//                        break;
//                    } case 16: { // norandom
//                        cin >> file;
//                        //////////// TODO
//                    } case 17: { // random
//                        //////////// TODO
//                    } case 18: { // sequence
//                        cin >> file;
////                        readFile = true;
//                        break;
//                    } case 19: { // restart the game
//                        break;
//                    } case 20: { // force
//                        // read a char
//                        break;
//                    }
//                }
//            }
//        }
//        
//        // End turn if drop/restart
//        if ((commandIndex == 6) || (commandIndex == 19)) {
//            break;
//        }
//        
//    }
//    
//    if (commandIndex == 19) { // Restart the game
//        return 1;
//    } else if (cin.eof()) { // EOF means terminate game
//        return 2;
//    } else { // End the turn normally
//        return 0;
//    }    ////// Force z?? Return a number from 3 to 9
    return 0;
}

// Prints a line of the player's grid
void Player::print(int n) {
//    grid->print(n);
}

void Player::setEffect(Effect effect) {
//    this->effect = effect;
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
////    grid.reset();
////    grid = make_unique<Grid>(width,height);
//    // Delete current level and get new level
//    lev = 0;
//    delete level;
////    level = Level::getLevel(0,scriptFile);
////    current.clear();
//    // current = level->createBlock();
    
}
