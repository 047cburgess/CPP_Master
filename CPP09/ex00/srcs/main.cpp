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
		BitcoinExchange myExchanger;
		myExchanger.setUpDatabase();
		myExchanger.launch(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "FATAL: " << e.what() << RESET << std::endl;
	}

}
