#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("DefaultShrubName", _signGrade, _executeGrade)
{
	std::cout << "Default PresidentialPardonForm constructor called: " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm(name, _signGrade, _executeGrade)
{
	std::cout << "PresidentialPardonForm Successfully constructed: " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{
	std::cout << "PresidentialPardonForm Successfully constructed: " << *this << std::endl;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);	
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destroyed: " << *this << std::endl;
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}
