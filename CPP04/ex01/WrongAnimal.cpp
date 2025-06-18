#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called." << std::endl; 
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

// Copy assignment
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = other;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal is making a sound..." << std::endl;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (this->type);
}
