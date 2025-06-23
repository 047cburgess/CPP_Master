#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", _signGrade, _executeGrade), _target("default")
{
	std::cout << "Default ShrubberyCreationForm constructor called: " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm("ShrubberyCreationForm", _signGrade, _executeGrade), _target(name)
{
	std::cout << "ShrubberyCreationForm Successfully constructed: " << *this << " target: " << name << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other.getTarget())
{
	std::cout << "ShrubberyCreation Successfully constructed: " << *this << " target: " << other.getTarget() << std::endl;
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return (*this);	
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destroyed: " << *this << " target: " << this->_target << std::endl;
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::string filename = this->_target + "_shrubbery";
	std::ofstream os;

	os.open(filename.c_str());
	if (os.is_open())
	{
		os << "       /\\" << std::endl;
		os << "      /**\\" << std::endl;
		os << "     /****\\" << std::endl;
		os << "    /******\\" << std::endl;
		os << "   /********\\" << std::endl;
		os << "       ||" << std::endl;
		os << "       ||" << std::endl;
		os << "       /\\" << std::endl << std::endl;

		os << "       /\\" << std::endl;
		os << "      /**\\" << std::endl;
		os << "     /****\\" << std::endl;
		os << "    /******\\" << std::endl;
		os << "   /********\\" << std::endl;
		os << "       ||" << std::endl;
		os << "       ||" << std::endl;
		os << "       /\\" << std::endl;
		os.close();
	}
	else
		throw FailedFileStreamException();
}

const std::string& 	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}
