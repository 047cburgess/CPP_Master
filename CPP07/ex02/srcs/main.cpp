#include "Array.hpp"
#include <iostream>
#include <string>
#include <exception>

int	main(void)
{
	try
	{
		Array<int> ints(5);
		for (int i = 0; i < 5; i++)
			ints[i] = i;
		Array<int> copyints = ints;
		std::cout << ints;
		std::cout << copyints;

		ints[0] = 1;
		std::cout << ints;

		ints[-1] = 1;
		std::cout << ints;

		ints[10] = 1;
		std::cout << ints;


	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Array<std::string> strs(10);
		std::cout << strs;

		strs[0] = "1";
		std::cout << strs;

		strs[1] = "2";
		std::cout << strs;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "creating 'strs_empty(5)'" << std::endl;
		Array<std::string> strs_empty(5);

		std::cout << "strs_empty.size() = " << strs_empty.size() << std::endl;

		Array<std::string> strs(10);
		std::cout << "Array<std::string> strs_empty(5) -> " << strs_empty;
		std::cout << "Array<std::string> strs(10) -> " << strs;

		strs[0] = "1";
		std::cout << "strs[0] = '1' -> " << strs;

		strs[1] = "2";
		std::cout << "strs[1] = '2' -> " << strs;

		strs = strs_empty;
		std::cout << "strs = strs_empty -> strs = " << strs;
		std::cout << "strs.size() = " << strs.size() << std::endl;
		strs[0] = "1";
		std::cout << "strs[0] = '1' -> " << strs;
		std::cout << "strs_empty[0] = ' ' -> " << strs_empty;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}
