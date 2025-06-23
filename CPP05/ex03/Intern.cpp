# include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << "Successfully constructed intern"<< std::endl;
	return ;
}

Intern::Intern(const Intern& other)
{
	*this = other;
	std::cout << "Successfully constructed intern" << std::endl;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern was destroyed" << std::endl;
}

AForm*	Intern::createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{

	// DO A FUNCTION POINTERS ARRAY LIKE IN PREVIOUS MODULE
	const std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm*	(Intern::*funcs[])(const std::string& target) = {&Intern::createRobotomy, &Intern::createPresidential, &Intern::createShrubbery };
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creating form " << name << " target " << target << std::endl;
			return (this->*funcs[i])(target);
		}
	}
	std::cout << "Form " << name << " not found. Intern could not create it. Forms: [robotomy request] [presidential pardon] [shrubbery creation] " << std::endl;
	return (0);
}
