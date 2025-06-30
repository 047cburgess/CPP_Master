#pragma once

class	Span
{
	private:
		unsigned int capacity;
		std::vector<int> values;
	public:
		Span();
		Span(unsigned int capacity);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void	addNumber(int n);
		int	shortestSpan() const;
		int	longestSpan() const;
};
