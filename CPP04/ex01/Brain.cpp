#include "Brain.hpp"

// Constructors

// DEFAULT
Brain::Brain()
{
	std::cout << "Default Brain constructor called." << std::endl;
}

// DESTRUCTOR
Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

// Copy assignment
Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);

// Copy constructor
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = other;
}
