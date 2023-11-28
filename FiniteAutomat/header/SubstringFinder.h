#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>

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

	void prefixFunction();
	size_t transition(size_t current_state, char signal);
};