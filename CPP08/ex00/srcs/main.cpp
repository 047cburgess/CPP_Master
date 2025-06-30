#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>


int	main(void)
{
	{

	std::vector<int> ints(10);
	std::vector<int>::iterator it = ints.begin();

	std::cout << "Filling int vector 0 - 10" << std::endl;
	for (int i = 0; it != ints.end(); i++)
	{
		ints[i] = i;
		it++;
	}
	

	std::cout << "Trying to find from  0 - 11 -> doesnt find 11" << std::endl;
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
		std::cout << "Filling char vector 'A' - 10" << std::endl;
		for (int i = 0; it != chars.end(); i++)
		{
			chars[i] = num;
			num++;
			it++;
		}

		std::cout << "Trying to find from  65 - 80 -> doesnt find from 75" << std::endl;
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
