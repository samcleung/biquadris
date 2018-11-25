#include <iostream>
//#include <string>
#include <vector>
#include "player.h"

using namespace std;

Player::Player(const std::string& name, const std::string& scriptFile) : name{name}, scriptFile{scriptFile} {}


// what to do with brown block

// Read in all the commands
void Player::turn() {
    string command;
    vector<string> commands {"left", "right", "up", "down", "clockwise", "counterclockwise",
                            "drop", "levelup", "leveldown", "I", "J", "L", "O", "S",
                             "Z", "T", "norandom", "random", "restart"};
    vector<int> indices;
    
    // Get block
//    vector<Block> blocks = level->getBlock();
//    current = &blocks.at(0);
    
    // Read input
    while(((cin >> command) && !cin.eof())) {
        int index = 0;
        int multiplier;
        int size = command.size();
        
        // Extract multiplier from the command
        for(int i = 0; i < size; ++i) {
            if(!((command.at(i) >= '0') && (command.at(i) <= '9'))) {
                index = i;
                break;
            }
        }
        
        if(index == 0) {
            // No multiplier
            multiplier = 1;
        } else {
            multiplier = stoi(command.substr(0,index));
        }
        string call = command.substr(index);
        
        int commandIndex = -1;
        int callSize = call.size();
        for(int j = 1; j < callSize+1; ++j) {
            int k = 0;
            for(auto &c: commands) {
                int cSize = c.size();
                if(call == c) {
                    commandIndex = k;
                    break;
                } else if((callSize <= cSize) && (call == c.substr(0,j))) {
                    indices.emplace_back(k);
                }
                k++;
            }
            if(commandIndex != -1) {
                indices.clear(); // Found the command character for character
                break;
            } else if(indices.size() == 1) {
                commandIndex = indices.at(0); // One match for command
                indices.clear();
                break;
            }
            indices.clear(); // More than one match for command, use next letter
        }
        
        // Finished reading in command
        
        if(commandIndex != -1) {
            // It was a valid command
            // Check commands that do not require multipliers first
            if((commandIndex >= 16) && (commandIndex <= 18)) {
                switch(commandIndex) {
                    case 16: { // norandom

                    } case 17: { // random

                    } case 18: { // restart the game

                    }
                }
            } else {
                // Commmands with multipliers
                for(int i = 0; i < multiplier; ++i) {
                    // Covers all transformations
                    if((commandIndex >=0) && (commandIndex <= 5)) {
                        current->transform(commands.at(commandIndex));
                    } else {
                        switch(commandIndex) {
                            case 6: { // drop
                                break;
                            } case 7: { // levelup
                                break;
                            } case 8: { // leveldown
                                break;
                            } case 9: { // I-block, change current block to this
                                break;
                            } case 10: { // J-block
                                break;
                            } case 11: { // L-block
                                break;
                            } case 12: { // O-block
                                break;
                            } case 13: { // S-block
                                break;
                            } case 14: { // Z-block
                                break;
                            } case 15: { // T-block
                                break;
                            }
                        }
                    }
                }
            }
        }
        
    }
    

    // EOF indicates terminate the entire game
    // If the turn is over add the transformed block to the grid
    
}

// Prints a line of the player's grid
void Player::print(int n) {
    
}

//void Player::setEffect(Game::Effect effect) {
//    this->effect = effect;
//}
