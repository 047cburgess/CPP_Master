// PSEUDO CODE //

// 1: Divide the elements into pairs
// 2: Sort the pairs (based on last num in the pair)
#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>

template <typename T>
void	printNums(const std::string message, T& container)
{
	std::cout << message;

	typename T::iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
};


int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Usage: ./PmergeMe x x x x x" << std::endl;
		return (1);
	}





	try
	{
		// TIME STAMP
		// START TIME = gettime
		PmergeMe<std::vector<int> > vectorValues;

		vectorValues.parse(&av[1]);
		vectorValues.sort();
		
		// 
		// PRINT

		PmergeMe<std::deque<int> > dequeValues;

		dequeValues.parse(&av[1]);
		dequeValues.sort();
		


	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

}

