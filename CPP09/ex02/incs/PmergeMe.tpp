#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe()
{

}


template <typename Container>
PmergeMe<Container>::~PmergeMe()
{
	
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
		if (next > length)
			break;
		result.push_back(next);
	}
	return (result);
}

template <typename Container>
std::vector<int> PmergeMe<Container>::getOrderOfInsertion(const Container& jacobs, size_t size) const
{
	std::vector<int> order;

	for (size_t i = 0; i < jacobs.size(); ++i) {
        order.push_back(jacobs[i]);
        for (int j = jacobs[i] - 1; j > jacobs[i - 1]; --j) {
            order.push_back(j);
        }
	}

    
    for (size_t i = jacobs[jacobs.size() - 1] + 1; i < size; ++i) {
        order.push_back(static_cast<int>(i));
    }
    
    return order;

}

template <typename Container>
Container PmergeMe<Container>::mergeInsertionSort(Container container)
{
	size_t n = container.size();
    
    // Base cases
    if (n <= 1) return (container);
    
    if (n == 2) {
        if (container[0] > container[1]) {
            std::swap(container[0], container[1]);
        }
        return (container);
    }
    
    // Form pairs: larger - smaller
    PairContainer pairs;
    bool has_odd = (n & 1);
    int odd_element = 0;
    
    if (has_odd) {
        odd_element = container.back();
        --n;
    }
    
    for (size_t i = 0; i < n; i += 2) {
        if (container[i] > container[i + 1]) {
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        } else {
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
        }
    }
    
    // Recursively sort larger elements -> main chain
    Container main_chain;
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        main_chain.push_back(it->first);
    }
    
    if (main_chain.size() > 1) {
        main_chain = sort(main_chain);
    }
    
    // Create pendant chain of smaller elements
    Container pendant_chain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first == main_chain[0]) {
            main_chain.insert(main_chain.begin(), pairs[i].second);
        } else {
            pendant_chain.push_back(pairs[i].second);
        }
    }
    
    // Insert pendant elements using Jacobsthal sequence
    if (pendant_chain.size() >= 1) {
        std::vector<int> jacobsthal_seq = genJacobsthalSequence(static_cast<int>(pendant_chain.size()));
        std::vector<int> insertion_order = getOrderOfInsertion(jacobsthal_seq, pendant_chain.size());
        
        for (size_t i = 0; i < pendant_chain.size(); ++i) {
            int index = insertion_order[i];
            typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pendant_chain[index]);
            main_chain.insert(pos, pendant_chain[index]);
        }
    }
    
    // Handle odd element
    if (has_odd) {
        typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), odd_element);
        main_chain.insert(pos, odd_element);
    }
    
    return (container);
}

template <typename Container>
void PmergeMe<Container>::sort()
{
	_values = mergeInsertionSort(_values);
}
