#include <iostream>
#include <string>
#include <vector>
#include "../header/SubstringFinder.h"

int main()
{
	//std::vector<int> p = { 1, 2, 1, 2 };
	//std::vector<int> t = { 1, 2, 1, 2, 1, 2, 5, 6, 7 };
	std::string p = "abab";
	std::string t = "abababxyz";

	SubstringFinder< std::string > kmp(p);
	
	std::vector<size_t> indexes = kmp(t);
	if (indexes.empty())
	{
		std::cout << "Pattern was not found!\n";
	}
	else 
	{
		for (size_t index : indexes)
		{
			std::cout << "Pattern was found at " << index << std::endl;
		}
	}

	return 0;
}