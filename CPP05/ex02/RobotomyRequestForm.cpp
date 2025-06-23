#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", _signGrade, _executeGrade), _target("default")
{
	std::cout << "Default RobotomyRequestForm constructor called: " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm("RobotomyRequestForm", _signGrade, _executeGrade), _target(name)
{
	std::cout << "RobotomyRequestForm Successfully constructed: " << *this << " target: " << name << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other.getTarget())
{
	std::cout << "RobotomyRequestForm Successfully constructed: " << *this << " target: " << this->_target << std::endl;
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return (*this);	
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destroyed: " << *this << " target: " << this->_target << std::endl;
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "** DRIIIIILLLLLLLLLIIIIIINNNNNNNNNGGGGGGG noise **" << std::endl;
	std::srand(time(0));
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << this->_target << " failed to be robotomized!" << std::endl;
}

const std::string& 	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}
