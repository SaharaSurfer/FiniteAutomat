#pragma once
#include <vector>
#include <functional>
#include <unordered_set>

template<typename Container>
class FiniteAutomat
{
public:
	typedef typename Container::value_type Symbol;

	FiniteAutomat
	(
		std::unordered_set<size_t> _states,
		std::unordered_set<Symbol> _alphabet,
		std::function<size_t(size_t, Symbol)> _transition_func, 
		size_t _initial_state,
		std::unordered_set<size_t> _final_states
	)
	{
		states = _states;
		alphabet = _alphabet;
		transition_func = _transition_func;
		current_state = _initial_state;
		final_states = _final_states;
	}

	bool operator()(Container input_chain)
	{
		for (Symbol symbol : input_chain)
		{
			if (alphabet.find(symbol) == alphabet.end())
			{
				return false;
			}

			current_state = transition_func(current_state, symbol);

			if (states.find(current_state) == states.end())
			{
				return false;
			}

			if (final_states.find(current_state) != final_states.end())
			{
				return true;
			}
		}
		return false;
	}
private:
	std::unordered_set<size_t> states;
	std::unordered_set<Symbol> alphabet;
	std::function<size_t(size_t, Symbol)> transition_func;
	size_t current_state;
	std::unordered_set<size_t> final_states;
};