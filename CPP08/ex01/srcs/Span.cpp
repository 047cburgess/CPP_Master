#include "Span.hpp"


Span::Span(): _capacity(0)
{
	return ;
}

Span::Span(unsigned int capacity): _capacity(capacity)
{
	std::cout << "Created span: capacity " << capacity << std::endl;
}

Span::Span(const Span& other): _capacity(other._capacity), _values(other._values)
{
	std::cout << "Created span: capacity " << _capacity << std::endl;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_capacity = other._capacity;
		this->_values = other._values;
	}
	return (*this);
}

Span::~Span()
{

}

void	Span::addNumber(int n)
{
	if (this->_values.size() == this->_capacity)
		throw std::range_error("This span is already at capacity");
	this->_values.push_back(n);
}

int	Span::shortestSpan(void) const
{
	if (this->_values.size() <= 1)
		throw std::range_error("Unable to find shortest span -> not enough elements");
	std::vector<int> copy = _values;	
	std::sort(copy.begin(), copy.end());

	std::vector<int>::iterator it = copy.begin();
	std::vector<int>::iterator ite = copy.end() - 1;

	int shortest = this->longestSpan();
	int test = 0;

	while (it != ite)
	{
		test = *(it + 1) - *it;
		if (test < shortest)
			shortest = test;
		it++;
	}
	std::cout << "Shortest span: " << shortest << std::endl;
	std::cout << "Sorted: ";
	for (unsigned long i = 0; i < this->_values.size(); i++)
		std::cout << "[" << copy[i] << "] ";
	std::cout << std::endl;
	return (shortest);
}

int	Span::longestSpan() const
{
	// Checking there's at least 2 elements
	if (this->_values.size() <= 1)
		throw std::range_error("Unable to find longest span -> not enough elements");

	// Copying the vector so it doesn't modify the original
	std::vector<int> copy = _values;	

	// Sorting the copy to identify the min and max values
	std::sort(copy.begin(), copy.end());

	int longest_span = copy.back() - copy.front();
	std::cout << "Longest span: " << longest_span << " (" << copy.back() << " - " << copy.front() << ")" << std::endl;
	return (longest_span);
}

void	Span::fill(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	while (start != end)
	{
		this->addNumber(*start);
		start++;
	}
}

void	Span::print(int info) const
{
	if (info)
	{
		std::cout << "Span size: " << this->_values.size() << std::endl;
		std::cout << "Span capacity: " << this->_capacity << std::endl;
	}
	
	std::cout << "Span values: ";
	for (unsigned long i = 0; i < this->_values.size(); i++)
		std::cout << "[" << _values[i] << "] ";
	std::cout << std::endl;
}
