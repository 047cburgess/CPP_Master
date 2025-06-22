#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("DefaultShrubName", _signGrade, _executeGrade)
{
	std::cout << "Default ShrubberyCreationForm constructor called: " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm(name, _signGrade, _executeGrade)
{
	std::cout << "ShrubberyCreationForm Successfully constructed: " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
	std::cout << "ShrubberyCreation Successfully constructed: " << *this << std::endl;
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);	
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destroyed: " << *this << std::endl;
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::cout << "Do form execution here..." << std::endl;
	std::string filename = this->getName() + "_shrubbery";
	std::ofstream os;

	try
	{
		os.open(filename.c_str());
		os.close();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}
