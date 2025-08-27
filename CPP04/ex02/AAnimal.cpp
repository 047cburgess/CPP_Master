#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called." << std::endl; 
}


// Destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called." << std::endl;
}

// Copy assignment
AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal copy assignment called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = other;
}

const std::string&	AAnimal::getType(void) const
{
	return (this->type);
}
