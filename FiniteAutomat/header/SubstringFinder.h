#pragma once
#include <vector>
#include <string>

class SubstringFinder
{
public:
	SubstringFinder(std::string _pattern);

	void setPattern(std::string _pattern);
	size_t operator()(size_t _state, char _signal);
private:
	std::string pattern;
	std::vector<size_t> prefixes;

	void prefixFunction();
};