#include "Animal.hpp"
#include "Dog.hpp"

// Default constructor
Dog::Dog(): Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called." << std::endl; 
}


// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

// Copy assignment
Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = other;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

