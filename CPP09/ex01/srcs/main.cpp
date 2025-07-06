#include <stack>
#include <iostream>
#include <string>
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN \"8 9 * 2\"" << std::endl;
		return (1);
	}

	try
	{
		std::string input = av[1];
		RPN rpn;
		rpn.calculate(input);
	}
	catch (const std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}
