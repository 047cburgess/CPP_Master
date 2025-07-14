#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe()
{

}


template <typename Container>
PmergeMe<Container>~::PmergeMe()
{
	
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other)
{

}

template <typename Container>
PmergeMe& PmergeMe<Container>::operator=(const PmergeMe& other)
{

}

template <typename Container>
void	PmergeMe<Container>::parse(char** nums)
{
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
		_values.push_back(static_cast<int>(value));
		i++;
	}
	_original = _values;
}

template <typename Container>
Container PmergeMe<Container>::genJacobsthalSequence(int length)
{
	Container result;
	

}


template <typename Container>
void	PmergeMe::sort(void)
{
	
}


