#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include "game/game.h"

using namespace std;

// command constants
const string STARTLEVEL = "-startlevel";
const string TEXT = "-text";
const string SEED = "-seed";
const string SCRIPTFILE = "-scriptfile";

// default script file constants
const string DEFAULTSF1 = "sequence1.txt";
const string DEFAULTSF2 = "sequence2.txt";
const string DEFAULTSFN = "sequenceN.txt";

// if command is "-scriptfileN" (for some positive int N) returns N, otherwise 0
int scriptFile(const string& command) {
	try {
		int x = SCRIPTFILE.length();
		string s{command.substr(0, x)};
		if (s == SCRIPTFILE) {
			istringstream iss{command.substr(x)};
			if (iss >> x) return x;
		}
	} catch (...) {}
	
	return 0;
}

int main(int argc, char *argv[]) {
	// create game
	Game game{};

	// create a map of players and scriptFiles
	//   (set P1 & P2 scriptFiles to defaults)
	map<int, string> scriptFiles;
	scriptFiles[1] = DEFAULTSF1;
	scriptFiles[2] = DEFAULTSF2;

	int startLevel;
	int seed;
	// setup game settings
	for (int i = 1; i < argc; ++i) {
		int n;
		string command{argv[i]};
		
		if (command == STARTLEVEL) {
			istringstream iss{argv[++i]};
			if (iss >> n) startLevel = n;
		} else if (command == TEXT) {
			//game.isTextOnly = true;
		} else if (command == SEED) {
			istringstream iss{argv[++i]};
			if (iss >> n) seed = n;
		} else {
			int fileNumber = scriptFile(command);
			if (fileNumber > 0) {
				scriptFiles[fileNumber] = argv[++i];
			}
		}
	}
	game.initialize(startLevel, seed);
	int maxMapKey = scriptFiles.rbegin()->first;
	int playerCount = 0;

	// create user prompt
	ostringstream prompt;
	prompt << "Input number of players (>=" << maxMapKey << "): ";

	// get player count
	cout << prompt.str();
	while ((!(cin >> playerCount) && !cin.eof()) || playerCount < maxMapKey) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
		cout << "Invalid player count." << endl;
		cout << prompt.str();
	}
	cout << endl;
	// add players to game
	for (int i = 1; i < playerCount+1; ++i) {
		// get player name, then add to game
		string playerName;
		cout << "P" << i << " name: ";
		cin >> playerName;
		if(scriptFiles.find(i) == scriptFiles.end()) {
			game.addPlayer(playerName, DEFAULTSFN);
        } else {
			game.addPlayer(playerName, scriptFiles[i]);
        }
	}
	
	game.play();
	
	return 0;
}
