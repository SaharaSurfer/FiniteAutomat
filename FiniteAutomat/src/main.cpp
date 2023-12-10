#include <iostream>
#include <string>
#include <functional>
#include <unordered_set>
#include "../header/FiniteAutomat.h"
#include "../header/SubstringFinder.h"

int main()
{
	std::string pattern = "abab";
	std::unordered_set<size_t> final_states = { pattern.size() };
	
	std::string text = "abababxyz";

	SubstringFinder kmp(pattern);
	FiniteAutomat< std::string > automat(kmp, 0, final_states);
	std::cout << automat(text);
	
	return 0;
}