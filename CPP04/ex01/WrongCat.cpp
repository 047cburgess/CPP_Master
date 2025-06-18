#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(): WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called." << std::endl; 
}


// Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

// Copy assignment
WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = other;
}

