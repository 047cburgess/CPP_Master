#include "ScalarConverter.hpp"
#include <limits>
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <cerrno>

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

void	ScalarConverter::convert(const std::string input)
{
	if (isPseudoLiteral(input))
		convertPseudoLiteral(input);
	else if (isChar(input))
		convertChar(input);
	else if (isInt(input))
		convertInt(input);
	else if (isDouble(input))
		convertDouble(input);
	else if (isFloat(input))
		convertFloat(input);
	else
		printImpossible();
}

void	printImpossible(void)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
}

void	convertChar(const std::string input)
{
	char c = input[0];
	int i = static_cast<int>(c);
	double d = static_cast<double>(c);
	float f = static_cast<float>(c);
	
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
}

void	convertInt(const std::string& input)
{
	char *endptr;
	long int result = std::strtol(input.c_str(), &endptr, 10);
	if (result < INT_MIN || result > INT_MAX)
	{
		printImpossible();
		return ;
	}
	int i = std::atoi(input.c_str());
	if (!isascii(i))
		std::cout << "char: impossible" << std::endl;
	else if (isascii(i) && isprint(i))
	{
		char c = static_cast<char>(i);
		std::cout << "char: " << "'" << c << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << i << std::endl;
	double d = static_cast<double>(i);
	float f = static_cast<float>(i);
	std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
}

int	getPrecision(const std::string& input)
{
	size_t dotPos = input.find('.') + 1;
        int i = 0;
	while (dotPos < input.length() && isdigit(input[dotPos]))
	{
		i++;
		dotPos++;
	}
	if (i == 0)
		return (1);
	return (i);
}

void	convertFloat(const std::string& input)
{
	char* endptr;
	errno = 0;
	double f = std::strtof(input.c_str(), &endptr);
	if (errno == ERANGE)
	{
		printImpossible();
		return ;
	}
	if (!isascii(f))
		std::cout << "char: impossible" << std::endl;
	else if (isascii(f) && isprint(f))
	{
		char c = static_cast<char>(f);
		std::cout << "char: " << "'" << c << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f < INT_MIN || f > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
	}
	double d = static_cast<double>(f);
	std::cout << "double: " << std::setprecision(getPrecision(input)) << std::fixed << d << std::endl;
	std::cout << "float: " << std::setprecision(getPrecision(input)) << std::fixed << f << "f" << std::endl;
}

void	convertDouble(const std::string& input)
{
	char* endptr;
	errno = 0;
	double d = std::strtod(input.c_str(), &endptr);
	if (errno == ERANGE)
	{
		printImpossible();
		return ;
	}
	if (!isascii(d))
		std::cout << "char: impossible" << std::endl;
	else if (isascii(d) && isprint(d))
	{
		char c = static_cast<char>(d);
		std::cout << "char: " << "'" << c << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
	std::cout << "double: " << std::setprecision(getPrecision(input)) << std::fixed << d << std::endl;
	if (d < FLT_MIN || d > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		float f = static_cast<float>(d);
		std::cout << "float: " << std::setprecision(getPrecision(input)) << std::fixed << f << "f" << std::endl;
	}
}

bool	isFloat(const std::string& input)
{
	size_t found = input.find(".");
	if (found == std::string::npos)
		return (false);
	if (input[input.length() - 1] != 'f')
		return (false);
	std::string trunc = input;
	trunc[input.length() - 1] = '\0';
	char* endptr;
	float result = std::strtof(trunc.c_str(), &endptr);
	(void)result;
	if (*endptr != '\0')
		return (false);
	return (true);
}

bool	isDouble(const std::string& input)
{
	std::size_t found = input.find(".");
	if (found == std::string::npos)
		return (false);
	found = input.find("f");
	if (found != std::string::npos)
		return (false);
	char* endptr;
	double result = std::strtod(input.c_str(), &endptr);
	(void)result;
	if (*endptr != '\0')
		return (false);
	return (true);
}

bool	isInt(const std::string& input)
{
	char* endptr;
	long int result = std::strtol(input.c_str(), &endptr, 10);
	(void)result;
	if (*endptr != '\0')
		return (false);
	return (true);
}

bool	isChar(const std::string& input)
{
	if (input.length() != 1 || !std::isprint(input[0]) || std::isdigit(input[0]))
		return (false);
	return (true);
}

void	convertPseudoLiteral(const std::string& input)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	
	char *endptr;
	float f;
	double d;
	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		f = std::strtof(input.c_str(), &endptr);
		d = static_cast<double>(f);
	}
	else
	{
		d = std::strtod(input.c_str(), &endptr);
		f = static_cast<float>(d);
	}
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

bool	isPseudoLiteral(const std::string& input)
{
	const std::string literals[6] = { "nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
	
	for (int i = 0; i < 6; i++)
	{
		if (input == literals[i])
			return (true);
	}
	return (false);
}
