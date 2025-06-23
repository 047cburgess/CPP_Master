#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


void	printHeader(void)
{
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "#####################  -----------  TESTING   ------------ #########################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << std::endl;
}

void	printFooter(void)
{
	std::cout << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "#####################  -----------  THE END   ------------ #########################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << std::endl;
}

void	printDivider(void)
{
	std::cout << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	printHeader();
	{
	{
	std::cout << "TESTING FORM COPY CONSTRUCTORS" << std::endl;
	ShrubberyCreationForm form1("form1");
	ShrubberyCreationForm form2(form1);
	ShrubberyCreationForm form3 = form2;
	Bureaucrat alice ("alice", 1);
	alice.signForm(form1);
	}

	printDivider();
	std::cout << "TESTING SUCCESSFUL FORMS CREATION" << std::endl;
	Intern	intern;

	std::cout << "Attempting to Create ShrubberyCreationForm, target home" << std::endl;
	AForm*	shrubbery = intern.makeForm("shrubbery creation", "home");

	printDivider();

	std::cout << "Attempting to Create Presidential, target Casey" << std::endl;
	AForm*	presidential = intern.makeForm("presidential pardon", "Casey");

	printDivider();

	std::cout << "Attempting to Create RobotomyRequest, target Casey" << std::endl;
	AForm*	robotomy = intern.makeForm("robotomy request", "Casey");

	printDivider();

	std::cout << "Attempting to Create non-existant form, target Casey" << std::endl;
	AForm*	nonexistant = intern.makeForm("non-existant form", "Casey");

	if (shrubbery != NULL)
		delete shrubbery;
	if (presidential != NULL)
		delete presidential;
	if (robotomy != NULL)
		delete robotomy;
	if (nonexistant != NULL)
		delete nonexistant;
	}
	printFooter();
}
