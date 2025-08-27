#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <list>
#include <cstdlib>

void	same_with_char();
void	random_gentest_list();
int	randomNumber();
void	multiple_occurances();

int	main(void)
{
	

	std::vector<int> ints(10);
	std::vector<int>::iterator it = ints.begin();

	std::cout << "Filling int vector 1 - 10" << std::endl;
	for (int i = 0; it != ints.end(); i++)
	{
		ints[i] = i + 1;
		it++;
	}
	

	std::cout << "Trying to find from  1 - 11 -> doesnt find 11" << std::endl;
	try
	{
		for (size_t i = 0; i < ints.size() + 1; i++)
			easyfind(ints, i);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: "<< e.what() << std::endl;
	}

	same_with_char();
	random_gentest_list();
	multiple_occurances();
}


void	multiple_occurances()
{
	std::vector<int> ints(10, 0);
	ints[4] = 5;
	ints[6] = 5;

	std::cout << "Created vector int array of 10.  ints[4] = 5. ints[6] = 5." << std::endl;
	std::vector<int>::iterator me = easyfind(ints, 5);
	std::vector<int>::iterator real = find(ints.begin(), ints.end(), 5);
	if (me != real)
		std::cout << "FAIL: iterators are not identical" << std::endl;
	else
		std::cout << "SUCCESS: iterators are identical" << std::endl;
	std::cout << "first index found: " << std::distance(ints.begin(), me) << std::endl;
}

int	randomNumber()
{
	return (std::rand() % 100);
}

void	random_gentest_list()
{
	std::srand(std::time(0));
	
	std::cout << "Creating list with size 100" << std::endl;
	std::list<int> ints(100);
	std::cout << "Allocating random numbers" << std::endl;
	std::generate(ints.begin(), ints.end(), randomNumber);
	std::cout << "List size: " << ints.size() << std::endl;
	std::list<int>::iterator it = ints.begin();
	std::list<int>::iterator ite = ints.end();
	for (int i = 0; it != ite; i++)
	{
		std::cout << i << ": " << *it << std::endl;
		it++;
	}
}

void	same_with_char()
{
	std::vector<char> chars(10);
	std::vector<char>::iterator it = chars.begin();

	int num = 65;
	std::cout << "Filling char vector 'A' - 'J'" << std::endl;
	for (int i = 0; it != chars.end(); i++)
	{
		chars[i] = num;
		num++;
		it++;
	}

	std::cout << "Trying to find from  'A' - 'Z' -> doesnt find from 'K'" << std::endl;
	try
	{
		for (size_t i = 65; i < 80; i++)
			easyfind(chars, i);

	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
