#include "AMateria.hpp"

// Default constructor
AMateria::AMateria(void)
{
	return;
}

// Parametric constructor
AMateria::AMateria(std::string const & type): type(type)
{
	return ;
}

// Copy Assignment constructor
AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->type = other.getType();
	return (*this);
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}
// Destructor
AMateria::~AMateria(void)
{
	return	;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "TEST ON AMATERIA::USE" << target.getName() << std::endl;
}

std::string const &	AMateria::getType() const
{
	return (this->type);
}
