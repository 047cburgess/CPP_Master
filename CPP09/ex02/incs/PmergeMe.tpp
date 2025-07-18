#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe()
{
	return ;
}


template <typename Container>
PmergeMe<Container>::~PmergeMe()
{
	return ;
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_values = other._values;
		_original = other._values;
		_type = other._type;
	}
	return (*this);

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
		if (find(_values.begin(), _values.end(), value) != _values.end())
			throw	std::invalid_argument("numbers cannot contain duplicates: " + numStr);
		_values.push_back(static_cast<int>(value));
		i++;
	}
	_original = _values;
}

template <typename Container>
std::vector<int> PmergeMe<Container>::genJacobsthalSequence(int length)
{
	std::vector<int> result;

	result.push_back(0);
	if (length == 0)
		return (result);

	result.push_back(1);
	if (length <= 3)
		return (result);
	
	result.push_back(3);
	int next;
	while (1)
	{
		size_t size = result.size();
		next = result[size - 1] + 2 * result[size - 2];
		if (next >= length)
			break;
		result.push_back(next);
	}
	return (result);
}


// JACOBSTHAL 0 1 3 5 9
// MAIN: 4 77 11
// ORIGINAL SEQUENCE 0 33 52 74 42 31 1 2 3 99
// ORDER OF INSERTION BY INDEX 0 -> 1 -> 3 -> 2 -> 5 -> 4 -> 9 -> 8 -> 7 -> 6
template <typename Container>
std::vector<int> PmergeMe<Container>::getOrderOfInsertion(const std::vector<int>& jacobs, size_t size) const
{
	std::vector<int> order;
	
	for (size_t i = 0; i < jacobs.size(); i++) 
	{
        	order.push_back(jacobs[i]);
		if (i != 0)
		{
        		for (int j = jacobs[i] - 1; j > jacobs[i - 1]; --j)
            		order.push_back(j);
		}
	}
    
	for (size_t i = jacobs[jacobs.size() - 1] + 1; i < size; i++) 
        	order.push_back(static_cast<int>(i));
    
    	return (order);
}

template <typename Container>
Container PmergeMe<Container>::mergeInsertionSort(Container container)
{
	size_t size = container.size();

	if (size <= 1)
		return (container);

	if (size == 2)
	{
	    if (container[0] > container[1])
	        std::swap(container[0], container[1]);
	    return (container);
	}
	
	// Form pairs: smallest on left, biggest on right
	PairContainer pairs;
	bool has_odd = (size & 1);
	int odd_value = 0;

	// If odd number of elements, put it to the side for later
	if (has_odd)
	{   
	    odd_value = container.back();
	    size--;
	}
	
	// Split into pairs in ascending order
	for (size_t i = 0; i < size; i += 2)
	{
	    int first = container[i];
	    int second = container[i + 1];
	
	    if (first < second)
	        pairs.push_back(std::make_pair(first, second));
	    else 
	        pairs.push_back(std::make_pair(second, first));
	}
	
	// Put the largest element of each pair into the main chain
	Container main_chain;
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++)
	        main_chain.push_back(it->second);
	
	// Apply the recursion to sort the main chain
	if (main_chain.size() > 1)
	    main_chain = mergeInsertionSort(main_chain);
	

	// Create pendant chain of smaller elements from the pairs
	Container pendant_chain;
	for (size_t i = 0; i < pairs.size(); i++) 
	        pendant_chain.push_back(pairs[i].first);
	
	
	// Insert smaller pendant elements into their place in main chain using Jacobsthal sequence
	if (pendant_chain.size() >= 1) 
	{
	    std::vector<int> jacobsthal_seq = genJacobsthalSequence(static_cast<int>(pendant_chain.size()));
	    std::vector<int> insertion_order = getOrderOfInsertion(jacobsthal_seq, pendant_chain.size());
	    
	    for (size_t i = 0; i < pendant_chain.size(); i++)
	    {
		// Get index of the element to insert
	        int index = insertion_order[i];

		// Get the position in the main chain you need to put it
	        typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pendant_chain[index]);

	        main_chain.insert(pos, pendant_chain[index]);
	    }
	}
	
	// At the end, put the odd element into the right place
	if (has_odd) 
	{
	    typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), odd_value);
	    main_chain.insert(pos, odd_value);
	}
	return (main_chain);
}

template <typename Container>
void PmergeMe<Container>::sort(const std::string& type)
{
	_type = type;
	_values = mergeInsertionSort(_values);

	Container test = _original;

	std::sort(test.begin(), test.end());
	if (test == _values)
		std::cout << "SORTED CORRECTLY, RESULT MATCHES STD::SORT" << std::endl;
	else
		std::cout << "SORTED INCORRECTLY, RESULT DOES NOT MATCH STD::SORT" << std::endl;
}

template <typename Container>
long	PmergeMe<Container>::calculateTimeTaken(const struct timeval& start, const struct timeval& end) const
{  
	long seconds = end.tv_sec - start.tv_sec;
    	long microseconds = end.tv_usec - start.tv_usec;
    	return (seconds * 1000000 + microseconds);
}

template <typename Container>
void	PmergeMe<Container>::printResult(const struct timeval& start, const struct timeval& end) const
{
	long timeTaken = calculateTimeTaken(start, end);
	std::cout << "Before: ";
	for (unsigned int i = 0; i < _original.size(); i++)
		std::cout << _original[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for (unsigned int i = 0; i < _values.size(); i++)
		std::cout << _values[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _original.size() << " elements with std::" << _type
	<< " : " << timeTaken << " ms" << std::endl << std::endl;
}

template <typename Container>
template <typename T>
void	PmergeMe<Container>::printSequence(const T& container, const std::string& prefix) const
{
	std::cout << prefix << " : ";
	for (unsigned int i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
	std::cout << std::endl;
}
