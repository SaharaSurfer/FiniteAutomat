#include <iostream>
#include <string>
#include <functional>
#include <unordered_set>
#include "../header/FiniteAutomat.h"
#include "../header/SubstringFinder.h"

int main()
{
	std::string pattern = "abab";
	std::string text = "abababxyz";
	std::unordered_set<size_t> states = { 0, 1, 2, 3, 4 };
	std::unordered_set<char> alphabet(text.begin(), text.end());
	std::unordered_set<size_t> final_states = { 4 };
	

	SubstringFinder kmp(pattern);
	FiniteAutomat< std::string > automat(states, alphabet, kmp, 0, final_states);
	std::cout << automat(text);
	
	return 0;
}