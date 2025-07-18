#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Usage: ./PmergeMe x x x x x" << std::endl;
		return (1);
	}

	try
	{
		struct timeval start, end;

		// VECTOR
		gettimeofday(&start, NULL);

		PmergeMe<std::vector<int> > vectorValues;

		vectorValues.parse(&av[1]);
		vectorValues.sort("vector");

		gettimeofday(&end, NULL);
		vectorValues.printResult(start, end);
		
		// DEQUE
		gettimeofday(&start, NULL);
		PmergeMe<std::deque<int> > dequeValues;

		dequeValues.parse(&av[1]);
		dequeValues.sort("deque");

		gettimeofday(&end, NULL);
		dequeValues.printResult(start, end);
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

}

