i#include <string>
#include <set>
#include <map>
#include <algorithm>
#include "command.h"

using namespace std;

set<string> Command::aliases = {
	"left",
	"right",
	"down",
	"clockwise",
	"counterclockwise",
	"drop",
	"levelup",
	"leveldown",
	"I",
	"J",
	"L",
	"O",
	"S",
	"Z",
	"T",
	"norandom",
	"random",
	"sequence",
	"restart"
};


// NOTE: use constants for aliases and commands values
// swap Command::Action and set<string>, when iterating, store enum in a vector. If vector len is 1, then that is the command 
map<set<string>, Command::Action> Command::commands = {
	{{"left"}, Command::Action::Left},
	{{"right"}, Command::Action::Right},
	{{"down"}, Command::Action::Down},
	{Command::Action::Clockwise, {"clockwise"}},
	{Command::Action::CounterClockwise, {"counterclockwise"}},
	{Command::Action::Drop, {"drop"}},
	{Command::Action::LevelUp, {"levelup"}},
	{Command::Action::LevelDown, {"leveldown"}},
	{Command::Action::I, {"I"}},
	{Command::Action::J, {"J"}},
	{Command::Action::L, {"L"}},
	{Command::Action::O, {"O"}},
	{Command::Action::S, {"S"}},
	{Command::Action::Z, {"Z"}},
	{Command::Action::T, {"T"}},
	{Command::Action::NoRandom, {"norandom"}},
	{Command::Action::Random, {"random"}},
	{Command::Action::Sequence, {"sequence"}},
	{Command::Action::Restart, {"restart"}},
	{Command::Action::Rename, {"rename"}},
	{Command::Action::AddAlias, {"addalias"}},
	{Command::Action::RemoveAlias, {"removealias"}}
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
}

Command::operator int() const {
	return static_cast<int>(action);
}

bool Command::execute() {

}

