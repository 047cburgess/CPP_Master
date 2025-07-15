#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <deque>

template <typename Container>
class	PmergeMe
{
	private:
		Container _original;
		Container _values;
		Container genJacobsthalSequence(int length);
		Container getOrderOfInsertion(const Container& jacobs, size_t size) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	parse(char **nums); // DONE
		void	sort(void);
		typedef typename Container::allocator_type allocator_type;
		typedef std::pair<int, int> pair_type;

};

#include "PmergeMe.tpp"
