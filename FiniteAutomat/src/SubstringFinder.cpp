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
	std::vector<size_t> results;

	if (text.size() < pattern.size())
	{
		return results;
	}
	
	size_t current_state = 0;
	for (size_t signal_ind = 0; signal_ind < text.size(); signal_ind++)
	{
		current_state = transition(current_state, text[signal_ind]);

		if (current_state == pattern.size())
		{
			results.push_back(signal_ind - current_state + 1);
			current_state = prefixes[current_state - 1];
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

size_t SubstringFinder::transition(size_t current_state, char signal)
{
	while (current_state > 0 && pattern[current_state] != signal) 
	{
		current_state = prefixes[current_state - 1];
	}
	return (pattern[current_state] == signal) ? current_state + 1 : 0;
}
