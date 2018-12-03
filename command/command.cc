#include <string>
#include <set>
#include <map>
#include <iostream>
#include "command.h"
#include "../game/game.h"

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
	{{"removealias"}, Command::Action::RemoveAlias},
	{{"help"}, Command::Action::Help}
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
			case Command::Action::Help:
				printHelp();
				break;
			case Command::Action::RenameAlias:
				if (Game::isBonusEnabled) {
					renameAlias();
					break;
				}
			case Command::Action::AddAlias:
				if (Game::isBonusEnabled) {
					addAlias();
					break;
				}
			case Command::Action::RemoveAlias:
				if (Game::isBonusEnabled) removeAlias();
				else cout << "ERROR: bonus mode not activated (-enablebonus)" << endl;
				break;
			default:
				return false;
		}

		executed = true;
		return true;
	}

	cout << "ERROR: command has already been executed" << endl;
	return false;
}

void Command::renameAlias() const {
	string oldAlias, newAlias;

	if (cin >> oldAlias && cin >> newAlias) {
		for (auto it = commands.begin(); it != commands.end(); ++it) {
			for (const auto& alias: it->first) {
				if (alias == oldAlias) {
					set<string> oldSet = it->first;
					Command::Action a = it->second;
					oldSet.erase(oldAlias);
					oldSet.insert(newAlias);
					commands.erase(it);
					commands.insert(pair<set<string>, Command::Action>{oldSet, a});
					cout << "Renamed alias \"" << oldAlias << "\" to \"" << newAlias<< "\"" << endl;
					return;
				}
			}
		}
	}

	cout << "ERROR: alias \"" << oldAlias << "\" does not exist" << endl;
}

void Command::addAlias() const {
	string oldAlias, newAlias;
	
	if (cin >> oldAlias && cin >> newAlias) {
		// exit if new alias already exists
		for (const auto& m: Command::commands) {
			if (m.first.find(newAlias) != m.first.end()) {
				cout << "ERROR: alias \"" << newAlias << "\" already exists" << endl;
				return;
			}
		}
		
		// add alias for a command
		for (auto it = commands.begin(); it != commands.end(); ++it) {
			for (const auto& alias: it->first) {
				if (alias == oldAlias) {
					set<string> oldSet = it->first;
					Command::Action a = it->second;
					oldSet.insert(newAlias);
					commands.erase(it);
					commands.insert(pair<set<string>, Command::Action>{oldSet, a});
					cout << "Added alias \"" << newAlias << "\" for \"" << oldAlias << "\"" << endl;
					return;
				}
			}
		}
	}

	cout << "ERROR: alias \"" << oldAlias << "\" does not exist" << endl;
}

void Command::removeAlias() const {
	string targetAlias;

	if (cin >> targetAlias) {
		for (auto it = commands.begin(); it != commands.end(); ++it) {
			for (const auto& alias: it->first) {
				if (targetAlias == alias) {
					if (it->first.size() == 1) {
						cout << "ERROR: cannot remove alias \"" << targetAlias << "\", last alias" << endl;
					} else {
						set<string> oldSet = it->first;
						Command::Action a = it->second;
						oldSet.erase(targetAlias);
						commands.erase(it);
						commands.insert(pair<set<string>, Command::Action>{oldSet, a});
						cout << "Removed alias \"" << targetAlias << "\"" << endl;
					}

					return;
				}
			}
		}
	}

	cout << "ERROR: alias \"" << targetAlias << "\" does not exist" << endl;
}

void Command::printHelp() const {
	cout << "-------------------------" << endl;
	cout << "All command aliases: " << endl;
	for (const auto& m: commands) {
		for (auto it = m.first.begin(), last = prev(m.first.end()); it != m.first.end(); ++it) {
			cout << *it;
			if (it != last) cout << ", ";
		}
		cout << endl;
	}
	cout << "-------------------------" << endl;
}
