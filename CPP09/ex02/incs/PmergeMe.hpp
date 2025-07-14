#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

template <typename Container>
class	PmergeMe
{
	private:
		Container _original;
		Container _values;
		Container genJacobsthalSequence(int length);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	parse(char **nums);
		void	sort(void);

};

#include "PmergeMe.tpp"
