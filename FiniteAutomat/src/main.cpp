#include <iostream>
#include <string>
#include "../header/SubstringFinder.h"

int main()
{
	std::string pattern = "xyz";
	std::string text = "abcuvwxyz";

	SubstringFinder kmp(pattern);

	std::vector<size_t> indexes = kmp(text);
	if (indexes.empty())
	{
		std::cout << "Pattern was not found!";
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