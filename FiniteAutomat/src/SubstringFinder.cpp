#include "../header/SubstringFinder.h"

SubstringFinder::SubstringFinder(std::string _pattern)
{
	setPattern(_pattern);
}

void SubstringFinder::setPattern(std::string _pattern)
{
	pattern = _pattern;
	prefixes = std::vector<size_t>(pattern.size(), 0);
	prefixFunction();
}

size_t SubstringFinder::operator()(size_t _state, char _signal)
{
	while (_state > 0 && pattern[_state] != _signal)
	{
		_state = prefixes[_state - 1];
	}
	return (pattern[_state] == _signal) ? _state + 1 : 0;
}

void SubstringFinder::prefixFunction()
{
	size_t j = 0;
	for (size_t i = 1; i < pattern.size(); i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = prefixes[j - 1];
		}

		if (pattern[i] == pattern[j])
		{
			++j;
		}

		prefixes[i] = j;
	}
}