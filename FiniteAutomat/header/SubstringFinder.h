#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>

typedef std::pair<size_t, size_t> state;

class SubstringFinder
{
public:
	SubstringFinder(std::string new_pattern);

	void setPattern(std::string new_pattern);
	std::string getPattern();

	std::vector<size_t> operator()(std::string text);
private:
	std::string pattern;
	std::vector<size_t> prefixes;
	std::map<std::pair<state, bool>, state> transitions;

	void prefixFunction();

	void setTransitions(size_t text_size);
	state getNextState(state current_state, bool signal);
};