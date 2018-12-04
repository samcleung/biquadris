#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <vector>
#include <iostream>
#include "../game/game.h"
#include "../grid/grid.h"
#include "../level/level.h"
#include "../block/block.h"
#include "../coord/coord.h"
#include "../common/enums.h"

class Game;

class Player {
	std::string name;
	std::string scriptFile;
	Effect effect = Effect::None;
	unsigned int score = 0;
    	int seed;
    	Game *game;
    	Grid *grid;
    	int initLevel;
    	int lev;
    	Level* level;
    	Block *current;
    	int dropsSinceClear;
    	std::vector<Block> queue;
    	Grid *nextGrid;
    	void setBlock(Block);
    	bool isHeavy();
    	void updateDropsSinceClear();
	unsigned int getDropBy();
	void readEffect(int);
	void update();
public:
    	static std::istream *in;
    	static std::string file;

	//Ctor for Player:
	//First Param is the Players Name
	//game is a  pointer the Game that created player
	//<<OPTIONAL>> Starting Level. Defaults to 0
	//<<OPTIONAL>> Scriptfile for Blocks generated in Level0. Defaults to sequence1.txt
	//<OPTIONAL>> Seed for generating random numbers. Defaults to 893 (AKA SAME NUMBERS NUMBERS
	// EVERY TIME THIS GAME IS RUN)
	Player(const std::string&, Game *game, int level = 0, std::string scriptfile = "sequence1.txt", int seed = 893);	

	//Runs 1 Turn of Player (Block is generated and dropped or Player loses)
	//Returns a StatusCode, which can either be one of Default (Nothing Special Happens), 
	// Restart (Player asked to restart Game), 
	StatusCode turn();

	//Prints the Line Specified. Must be a value from 0 - 25
	void print(int);

	//Applies an Effect to the Player. Second Parameter is optional, only applies
	// if FORCE is the effect, and it specified which block to turn the players into
	void setEffect(Effect, Block::Type force = Block::Type::T);

	//Returns the current score of the player
	unsigned int getScore();

	//Returns the Name of the player
    	const std::string getName();

	//Restarts the Player. Should be called when the Player has asked the Game to be Restarted
    	void reset();

	//Clears the Board. Deletes all the heap allocated memory. 
    	void clear();
};

#endif
