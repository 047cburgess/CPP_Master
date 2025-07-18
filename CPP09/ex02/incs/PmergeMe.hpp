#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <deque>
#include <sys/time.h>

template <typename Container>
class	PmergeMe
{
	private:
		Container _original;
		Container _values;
		std::string _type;
		typedef std::pair<int, int> pair_type;
		typedef std::vector<pair_type> PairContainer;
		std::vector<int> genJacobsthalSequence(int length);
		std::vector<int> getOrderOfInsertion(const std::vector<int>& jacobs, size_t size) const;
		Container mergeInsertionSort(Container container);
		template <typename T>
		void	printSequence(const T& container, const std::string& prefix) const;
		long	calculateTimeTaken(const struct timeval& start, const struct timeval& end) const;
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

	public:
		PmergeMe();
		~PmergeMe();

		void	parse(char **nums);
		void	sort(const std::string& type);
		void	printResult(const struct timeval& start, const struct timeval& end) const;

};

#include "PmergeMe.tpp"
