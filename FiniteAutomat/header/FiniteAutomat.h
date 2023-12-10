#pragma once
#include <vector>
#include <functional>
#include <unordered_set>

template<typename Container>
class FiniteAutomat
{
public:
	typedef typename Container::value_type Symbol;

	FiniteAutomat(std::function<size_t(size_t, Symbol)> _transition_func, size_t _initial_state,
		std::unordered_set<size_t> _final_states)
	{
		transition_func = _transition_func;
		current_state = _initial_state;
		final_states = _final_states;
	}

	bool operator()(Container input_chain)
	{
		for (Symbol symbol : input_chain)
		{
			current_state = transition_func(current_state, symbol);
			if (final_states.find(current_state) != final_states.end())
			{
				return 1;
			}
		}
		return 0;
	}
private:
	std::function<size_t(size_t, Symbol)> transition_func;
	size_t current_state;
	std::unordered_set<size_t> final_states;
};