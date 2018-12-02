#include <string>
#include <set>
#include <map>
#include <iostream>
#include "command.h"

using namespace std;

// invarient: no duplicate aliases must exist
map<set<string>, Command::Action> Command::commands = {
	{{"left"}, Command::Action::Left},
	{{"right"}, Command::Action::Right},
	{{"down"}, Command::Action::Down},
	{{"clockwise"}, Command::Action::Clockwise},
	{{"counterclockwise"}, Command::Action::CounterClockwise},
	{{"drop"}, Command::Action::Drop},
	{{"levelup"}, Command::Action::LevelUp},
	{{"leveldown"}, Command::Action::LevelDown},
	{{"I"}, Command::Action::I},
	{{"J"}, Command::Action::J},
	{{"L"}, Command::Action::L},
	{{"O"}, Command::Action::O},
	{{"S"}, Command::Action::S},
	{{"Z"}, Command::Action::Z},
	{{"T"}, Command::Action::T},
	{{"norandom"}, Command::Action::NoRandom},
	{{"random"}, Command::Action::Random},
	{{"sequence"}, Command::Action::Sequence},
	{{"restart"}, Command::Action::Restart},
	{{"renamealias"}, Command::Action::RenameAlias},
	{{"addalias"}, Command::Action::AddAlias},
	{{"removealias"}, Command::Action::RemoveAlias}
	//{{"print"}, Command::Action::Print}
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
	int inputLen = input.length();

	for (int i = 1; i <= inputLen; ++i) {
		for (auto mapIt = commands.begin(), end = commands.end(); mapIt != end && exactMatch == end; ++mapIt) {
			for (auto setIt = mapIt->first.begin(); setIt != mapIt->first.end(); ++setIt) {
				string command = *setIt;
				int commandLen = command.length();
				if (input == command) {
					exactMatch = mapIt;
				} else if ((inputLen <= commandLen) && (input == command.substr(0, i) &&
						(!partialMatches.size() || partialMatches.back() != mapIt))) {
					partialMatches.emplace_back(mapIt);
				}
			}
		}

		if (exactMatch != commands.end()) {
			return exactMatch->second;
		} else if (partialMatches.size() == 1) {
			return partialMatches[0]->second;
		}
		partialMatches.clear();
	}
	
	return Command::Action::None;
}

Command::operator int() const {
	return static_cast<int>(action);
}

bool Command::operator()() {
	if (!executed) {
		switch(action) {
			case Command::Action::RenameAlias:
				renameAlias();
				break;
			case Command::Action::AddAlias:
				addAlias();
				break;
			case Command::Action::RemoveAlias:
				removeAlias();
				break;
			default:
				return false;
		}

		executed = true;
		return true;
	}

	// cout ERROR command has already been executed
	return false;
}

void Command::renameAlias() {
	string oldAlias, newAlias;

	if (cin >> oldAlias && cin >> newAlias) {
		for (const auto& m: commands) {
			auto loc = m.first.find(oldAlias);
			if (loc != m.first.end()){
				m.first.erase(loc);
				m.first.insert(newAlias);
				// cout alias x renamed to y
				return;
			}
		}
	}

	// cout ERROR alias x does not exist
}

void Command::addAlias() {
	string oldAlias, newAlias;
	
	if (cin >> oldAlias && cin >> newAlias) {
		// exit if new alias already exists
		for (const auto& m: Command::commands) {
			if (m.first.find(newAlias) != m.first.end()) {
				// cout ERROR alias y already exists
				return;
			}
		}
		
		// add alias for a command
		for (const auto& m: Command::commands) {
			if (m.first.find(oldAlias) != m.first.end()) {
				m.first.insert(newAlias);
				// cout added alias x for y
				return;
			}
		}
	}

	// cout ERROR alias x does not exist
}

void Command::removeAlias() {
	string alias;

	if (cin >> alias) {
		for (const auto& m: Command::commands) {
			auto loc = m.first.find(alias);
			if (loc != m.first.end()) {
				if (m.first.size() == 1)
					// cout ERROR cannot remove alias x, last alias
				else {
					m.first.erase(loc);
					// cout removed alias x
				}					
				return
			}
		}
	}

	// cout ERROR alias x does not exist
}

