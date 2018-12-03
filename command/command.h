#ifndef __COMMAND_H__
#define __COMMAND_H__
#include <string>
#include <set>
#include <map>
#include <vector>

struct Command {
	enum class Action {
		None = -1,
		Left,
		Right,
		Down,
		Clockwise,
		CounterClockwise,
		Drop,
		LevelUp,
		LevelDown,
		I,
		J,
		L,
		O,
		S,
		Z,
		T,
		NoRandom,
		Random,
		Sequence,
		Restart,
		RenameAlias,
		AddAlias,
		RemoveAlias,
		Help
	};

	const unsigned int multiplier;

	Command(std::string input);
	operator int() const;
	bool operator()(); // executes command on Command class, returning true if valid

	//Asks the user to rename Alias's for commands
	//SIDE EFFECT: READS IN 2 wORDS FROM STD::IN
	void renameAlias() const;

	//Add's an Alias 
	//SIDE EFFECT: READS IN 2 wORDS FROM STD::IN. First word is old alias. Second word is new Alias
	// which is replacing that word
	void addAlias() const;

	//Removes an Alias
	//SIDE EFFECT: READS IN 2 wORDS FROM STD::IN.First word is old alias and second word is current alias for it
	void removeAlias() const;

	//Prins to std::cout the list of commands that the user has
	void printHelp() const;
	static void prompt(const std::string& pName) { std::cout << "[" << pName << "] Enter a command: "; }
	static void promptInvalid() { std::cout << "ERROR: Invalid command. For a complete list of all command aliases, enter \"help\"." << std::endl; }

	private:
	bool executed = false;
	const Action action;
	unsigned int getMultiplier(std::string&);
	Action getAction(const std::string&);
	static std::map<std::set<std::string>, Action> commands;
};

#endif
