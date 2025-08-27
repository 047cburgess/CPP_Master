#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#define INFO 1
#define NO_INFO 0

class	Span
{
	private:
		unsigned int _capacity;
		std::vector<int> _values;
		Span();
	public:
		Span(unsigned int capacity);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void	addNumber(int n);
		int	shortestSpan() const;
		int	longestSpan() const;
		void	fill(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void	print(int info) const;
};
