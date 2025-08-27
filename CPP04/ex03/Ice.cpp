#include "Ice.hpp"
#include <iostream>
#include <string>

Ice::Ice(): AMateria("ice")
{
	return	;
}

Ice::Ice(const Ice& other): AMateria(other)
{
	return	;
}

Ice&	Ice::operator=(const Ice& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Ice::~Ice()
{
	return	;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
