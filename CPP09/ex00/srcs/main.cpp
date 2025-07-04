#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc <input.txt>" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange myExchanger(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "FATAL: " << e.what() << std::endl;
	}

}
