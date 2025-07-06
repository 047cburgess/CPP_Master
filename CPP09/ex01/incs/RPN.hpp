#pragma once
#include <string>
#include <stack>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "MutantStack.hpp"

class RPN
{
	private:
		MutantStack<int> stack;

		int	pop(void);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
	public:
		RPN();
		~RPN();

		void	calculate(std::string& input);
		void	print_stack(void) const;
};
