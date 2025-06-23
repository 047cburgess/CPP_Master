#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", _signGrade, _executeGrade), _target("default")
{
	std::cout << "Default PresidentialPardonForm constructor called: " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm("PresidentialPardonForm", _signGrade, _executeGrade), _target(name)
{
	std::cout << "PresidentialPardonForm Successfully constructed: " << *this << " target: " << name << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other.getTarget())
{
	std::cout << "PresidentialPardonForm Successfully constructed: " << *this << " target: " << other.getTarget() << std::endl;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return (*this);	
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destroyed: " << *this << " target: " << this->_target << std::endl;
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}

const std::string& 	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}
