#pragma once

#include <string>
#include <iostream>
#include <stack>
#include "utils.hpp"

template <class T>
class	MutantStack: public std::stack<T>
{

	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
};

#include "MutantStack.tpp"
