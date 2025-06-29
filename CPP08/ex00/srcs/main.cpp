#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>


int	main(void)
{
	{

	std::vector<int> ints(10);
	std::vector<int>::iterator it = ints.begin();


	for (int i = 0; it != ints.end(); i++)
	{
		ints[i] = i;
		it++;
	}

	try
	{
		for (size_t i = 0; i < ints.size() + 1; i++)
			easyfind(ints, i);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	}


	{
		std::vector<char> chars(10);
		std::vector<char>::iterator it = chars.begin();

		int num = 65;
		for (int i = 0; it != chars.end(); i++)
		{
			chars[i] = num;
			num++;
			it++;
		}

		try
		{
			for (size_t i = 65; i < 80; i++)
				easyfind(chars, i);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

}
