#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("DefaultShrubName", _signGrade, _executeGrade)
{
	std::cout << "Default RobotomyRequestForm constructor called: " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm(name, _signGrade, _executeGrade)
{
	std::cout << "RobotomyRequestForm Successfully constructed: " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other)
{
	std::cout << "RobotomyRequestForm Successfully constructed: " << *this << std::endl;
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);	
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destroyed: " << *this << std::endl;
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "** DRIIIIILLLLLLLLLIIIIIINNNNNNNNNGGGGGGG noise **" << std::endl;
}
