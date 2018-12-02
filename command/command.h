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
		RemoveAlias
		//Print
	};

	const unsigned int multiplier;

	Command(std::string input);
	operator int() const;
	bool operator==(const Action&) const;
	bool operator()(); // executes command on Command class, returning true if valid
	void renameAlias();
	void addAlias();
	void removeAlias();

	private:
	bool executed = false;
	const Action action;
	unsigned int getMultiplier(std::string&);
	Action getAction(const std::string&);
	static std::map<std::set<std::string>, Action> commands;
};

bool operator==(const Command::Action&, const Command&);

#endif
