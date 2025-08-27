#include "Animal.hpp"

// Default constructor
Animal::Animal(): type("default")
{
	std::cout << "Animal default constructor called." << std::endl; 
}


// Destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

// Copy assignment
Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

// Copy constructor
Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = other;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal is making a sound..." << std::endl;
}

const std::string&	Animal::getType(void) const
{
	return (this->type);
}
