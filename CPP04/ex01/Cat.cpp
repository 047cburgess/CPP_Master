#include "Animal.hpp"
#include "Cat.hpp"

// Default constructor
Cat::Cat(): Animal(), brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat default constructor called." << std::endl; 
}


// Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->brain;
}

// Copy assignment
Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment called." << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
	this->brain = new Brain(*other.brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

