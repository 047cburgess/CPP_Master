// PSEUDO CODE //

// 1: Divide the elements into pairs
// 2: Sort the pairs (based on last num in the pair)
#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>

template <typename T>
void	printNums(T& container)
{
	typename T::iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
};

std::vector<int>	parseInput(char** nums)
{
	std::vector<int> result;
	int i = 0;
	while (nums[i])
	{
		char* endptr;
		std::string numStr = nums[i];
		long	value = std::strtol(nums[i], &endptr, 10);
		if (*endptr != '\0' || (value < 0 || value > INT_MAX))
			throw	std::invalid_argument("not positive integer: " + numStr);
		if (find(result.begin(), result.end(), value) != result.end())
			throw	std::invalid_argument("numbers cannot contain duplicates: " + numStr);
		result.push_back(static_cast<int>(value));
		i++;
	}
	return (result);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Usage: ./PmergeMe x x x x x" << std::endl;
		return (1);
	}





	try
	{
		std::vector<int> nums = parseInput(&av[1]);
		printNums(nums);


		//PmergeMe vector;
		//vector.sort();


	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}

}

