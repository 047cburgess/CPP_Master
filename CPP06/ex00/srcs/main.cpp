#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert <X>" << std::endl;
		return (1);
	}
	
	ScalarConverter::convert(av[1]);
	return (0);
	{	
	// IF IT'S A CHAR
	std::cout << "TEST CHAR" << std::endl;
	char c = 'c';
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl << std::endl;
	}
	{
	// IF IT'S AN INT
	std::cout << "TEST INT" << std::endl;
	int i = 65;
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl << std::endl;
	}
	{
	// IF IT'S A FLOAT
	std::cout << "TEST FLOAT 1" << std::endl;
	float f = 34.143f;
	int i = static_cast<int>(f);
	char c = static_cast<char>(f);
	double d = static_cast<double>(f);

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl << std::endl;
	}
	{
	// IF IT'S A FLOAT
	std::cout << "TEST FLOAT 2" << std::endl;
	float f = 34.0f;
	int i = static_cast<int>(f);
	char c = static_cast<char>(f);
	double d = static_cast<double>(f);

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl << std::endl;
	}
}
