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

const std::string&	Brain::getIdea(int index) const
{
	static const std::string invalidIdea = "";

	if (index < 0 || index > 99)
	{
		std::cerr << "Invalid Idea index." << std::endl;
		return (invalidIdea);
	}
	else
		return (this->ideas[index]);
}

void	Brain::setIdea(int index, std::string what)
{
	if (index < 0 || index > 99)
		std::cerr << "Invalid Idea index." << std::endl;
	else
		this->ideas[index] = what;
}
