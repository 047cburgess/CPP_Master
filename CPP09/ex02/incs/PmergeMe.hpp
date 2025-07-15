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
		std::vector<int> genJacobsthalSequence(int length);
		std::vector<int> getOrderOfInsertion(const Container& jacobs, size_t size) const;
		Container mergeInsertionSort(Container container);

	public:
		typedef std::pair<int, int> pair_type;
		typedef std::vector<pair_type> PairContainer;
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	parse(char **nums); // DONE
		void	sort(void);

};

#include "PmergeMe.tpp"
