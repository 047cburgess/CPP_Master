#include "Brain.hpp"

// Constructors

// DEFAULT
Brain::Brain()
{
	std::cout << "Default Brain constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "Empty idea.";
	}
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
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

// Copy constructor
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}
