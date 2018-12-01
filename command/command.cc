#include <string>
#include <set>
#include <map>
#include <algorithm>
#include "command.h"

using namespace std;

// command constants to initialize class
const string LEFT = "left";
const string RIGHT = "right";
const string DOWN = "down";
const string CLOCKWISE = "clockwise";
const string COUNTERCLOCKWISE = "counterclockwise";
const string DROP = "drop";
const string LEVELUP = "levelup";
const string LEVELDOWN = "leveldown";
const string I = "I";
const string J = "J";
const string L = "L";
const string O = "O";
const string S = "S";
const string Z = "Z";
const string T = "T";
const string NORANDOM = "norandom";
const string RANDOM = "random";
const string SEQUENCE = "sequence";
const string RESTART = "restart";
const string RENAMEALIAS = "renamealias";
const string ADDALIAS = "addalias";
const string REMOVEALIAS = "removealias";
const string PRINT = "print";

set<string> Command::aliases = {
	LEFT,
	RIGHT,
	DOWN,
	CLOCKWISE,
	COUNTERCLOCKWISE,
	DROP,
	LEVELUP,
	LEVELDOWN,
	I,
	J,
	L,
	O,
	S,
	Z,
	T,
	NORANDOM,
	RANDOM,
	SEQUENCE,
	RESTART,
	RENAMEALIAS,
	ADDALIAS,
	REMOVEALIAS,
	PRINT
};


// NOTE: use constants for aliases and commands values
// swap Command::Action and set<string>, when iterating, store enum in a vector. If vector len is 1, then that is the command 
map<set<string>, Command::Action> Command::commands = {
	{{LEFT}, Command::Action::Left},
	{{RIGHT}, Command::Action::Right},
	{{DOWN}, Command::Action::Down},
	{{CLOCKWISE}, Command::Action::Clockwise},
	{{COUNTERCLOCKWISE}, Command::Action::CounterClockwise},
	{{DROP}, Command::Action::Drop},
	{{LEVELUP}, Command::Action::LevelUp},
	{{LEVELDOWN}, Command::Action::LevelDown},
	{{I}, Command::Action::I},
	{{J}, Command::Action::J},
	{{L}, Command::Action::L},
	{{O}, Command::Action::O},
	{{S}, Command::Action::S},
	{{Z}, Command::Action::Z},
	{{T}, Command::Action::T},
	{{NORANDOM}, Command::Action::NoRandom},
	{{RANDOM}, Command::Action::Random},
	{{SEQUENCE}, Command::Action::Sequence},
	{{RESTART}, Command::Action::Restart},
	{{RENAMEALIAS}, Command::Action::RenameAlias},
	{{ADDALIAS}, Command::Action::AddAlias},
	{{REMOVEALIAS}, Command::Action::RemoveAlias},
	{{PRINT}, Command::Action::Print}
};


// copy of string as param, will be modified by getMultiplier
Command::Command(string input) : multiplier{getMultiplier(input)}, action{getAction(input)} {}

unsigned int Command::getMultiplier(string& input) {
	unsigned int index = 0;
	for (auto i = index; i < input.length(); ++i) {
		if (input[i] < '0' || input[i] > '9') {
			index = i;
			break;
		}
	}

	if (index) {
		unsigned int x = stoi(input.substr(0, index));
		input = input.substr(index);
		return x;
	}
	
	return 1;
}

Command::Action Command::getAction(const string& input) {
	vector<map<set<string>, Command::Action>::const_iterator> partialMatches;
	auto exactMatch = commands.end();
	//map<set<string>, Command::Action>::const_iterator exactMatch = commands.end();
	
	int inputLen = input.length();
	for (int i = 1; i < inputLen; ++i) {
		for (auto mapIt = commands.begin(), end = commands.end(); mapIt != end && exactMatch != end; ++mapIt) {
			for (auto setIt = mapIt->first.begin(); setIt != mapIt->first.end(); ++setIt) {
				string command = *setIt;
				int commandLen = command.length();
				if (input == command) {
					exactMatch = mapIt;
				} else if ((inputLen <= commandLen) && (input == command.substr(0, i) && partialMatches.back() != mapIt)) {
					partialMatches.emplace_back(mapIt);
				}
			}
		}

		if (exactMatch != commands.end()) {
			return exactMatch->second;
			break;
		} else if (partialMatches.size() == 1) {
			return partialMatches[0]->second;
			break;
		}
		partialMatches.clear();
	}
	
	return Command::Action::None;
	
	/*
	vector<int> indices;
	int commandIndex = -1; // coresponds to Command::Action::None

	inputLen = input.length();
	for (int j = 1; j <= inputLen; ++j) {
		int k = 0;
		for (auto &c: commands) {
			int cLen = c.length();
			if (input == c) {
				commandIndex = k;
				break;
			} else if ((inputLen <= cLen) && (input == c.substr(0,j))) {
				indices.emplace_back(k);
			}
			k++;
		}
		if (commandIndex != -1) {
			// Found the command character for character
			break;
		} else if (indices.size() == 1) {
			commandIndex = indices[0]; // One match for command
			break;
		}

		indices.clear(); // More than one match for command, use next letter
	}

	return static_cast<Command::Action>(commandIndex);
	*/
	return Command::Action::None;
}

Command::operator int() const {
	return static_cast<int>(action);
}

bool Command::execute() {
	return false;
}

