#include "ScalarConverter.hpp"
#include <limits.h>
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <errno.h>

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
	// detect the type passed
	// convert it to its proper type
	// explicitly convert it to the three other data types
	// print out the results
	if (isPseudoLiteral(input))
		std::cout << input << " is pseudo literal." << std::endl; //convertPseudoLiteral(input);
	else if (isChar(input))
		std::cout << input << " is char." << std::endl; //convertChar(input);
	else if (isInt(input))
		std::cout << input << " is int." << std::endl; //convertChar(input);
	else if (isDouble(input))
		std::cout << input << " is double." << std::endl; //convertChar(input);
	else
		std::cout << input << " is not recognised" << std::endl;
//	else if (isFloat(input))
//		convertFloat(input);
//	else
//		convertImpossible();
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
	errno = 0;
	double result = std::strtod(input.c_str(), &endptr);
	std::cout << result << std::endl;
	if (*endptr != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	return (true);

}

bool	isInt(const std::string& input)
{
	int len = input.length();
	char* endptr;
	int i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == len)
		return (false);
	for (int j = i; j < len; j++)
	{
		if (!isdigit(input[j]))
			return (false);
	}
	long int result = std::strtol(input.c_str(), &endptr, 10);
	if (result < INT_MIN || result > INT_MAX)
		return (false);
	return (true);
}

bool	isChar(const std::string& input)
{
	if (input.length() != 1 || !std::isprint(input[0]) || std::isdigit(input[0]))
		return (false);
	return (true);
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



//int atoi(str.c_str())
//float std::stof
//double std::stod / atof
