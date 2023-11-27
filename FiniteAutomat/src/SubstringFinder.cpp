#include "../header/SubstringFinder.h"

SubstringFinder::SubstringFinder(std::string new_pattern)
{
	setPattern(new_pattern);
}

void SubstringFinder::setPattern(std::string new_pattern)
{
	pattern = new_pattern;
	prefixes = std::vector<size_t>(pattern.size(), 0);
	prefixFunction();
}

std::string SubstringFinder::getPattern()
{
	return pattern;
}

std::vector<size_t> SubstringFinder::operator()(std::string text)
{
	setTransitions(text.size());
	state current_state = state(0, 0);

	std::vector<size_t> results;

	while (current_state.second < text.size())
	{
		bool signal = pattern[current_state.first] == text[current_state.second];
		current_state = getNextState(current_state, signal);

		if (current_state.first == pattern.size())
		{
			results.push_back( current_state.second - current_state.first );
			current_state.first = prefixes[current_state.first - 1];
		}
	}
	return results;
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

void SubstringFinder::setTransitions(size_t text_size)
{
	transitions.clear();

	for (size_t i = 0; i < pattern.size(); i++)
	{
		for (size_t j = 0; j < text_size; j++)
		{
			transitions[std::make_pair(state(i, j), true)] = state(i + 1, j + 1);
			transitions[std::make_pair(state(i, j), false)] = i != 0 ? state(prefixes[i - 1], j) : state(i, j + 1);
		}
	}
}

state SubstringFinder::getNextState(state current_state, bool signal)
{
	return transitions[std::make_pair(current_state, signal)];
}