#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert <X>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
