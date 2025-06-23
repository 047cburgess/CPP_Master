#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


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
	std::cout << "TESTING SUCCESSFUL SHRUBBERY FORM EXECUTION" << std::endl;
	try
	{
		std::cout << "Attempting to Create ShrubberyCreationForm: home, notSigned, gradeToSign(145), gradeToExecute(137)" << std::endl;
		ShrubberyCreationForm	form("home");
		Bureaucrat	alice("Alice", 145);
		alice.signForm(form);
		Bureaucrat	bob("Bob", 137);
		
		std::cout << "bob.executeForm(form)" << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	std::cout << "TESTING SUCCESSFUL ROBOTOMY FORM EXECUTION" << std::endl;
	try
	{
		std::cout << "Attempting to Create RobotomyRequestForm: home, notSigned, gradeToSign(72), gradeToExecute(45)" << std::endl;
		RobotomyRequestForm	form("Casey");
		Bureaucrat	alice("Alice", 72);
		alice.signForm(form);
		Bureaucrat	bob("Bob", 5);
		
		std::cout << "bob.executeForm(form)" << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	std::cout << "TESTING SUCCESSFUL PRESIDENTIAL FORM EXECUTION" << std::endl;
	try
	{
		std::cout << "Attempting to Create PresidentialPardonForm: casey, notSigned, gradeToSign(25), gradeToExecute(5)" << std::endl;
		PresidentialPardonForm	form("Casey");
		Bureaucrat	alice("Alice", 24);
		alice.signForm(form);
		Bureaucrat	bob("Bob", 5);
		
		std::cout << "bob.executeForm(form)" << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	std::cout << "TESTING FAILED SHRUBBERY FORM EXECUTION: executor bob grade is too low" << std::endl;
	try
	{
		std::cout << "Attempting to Create ShrubberyCreationForm: failedwork, notSigned, gradeToSign(145), gradeToExecute(137)" << std::endl;
		ShrubberyCreationForm	form("failedwork");
		Bureaucrat	alice("Alice", 145);
		alice.signForm(form);
		Bureaucrat	bob("Bob", 150);

		bob.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	std::cout << "TESTING FAILED ROBOTOMY FORM EXECUTION: executor bob grade is too low" << std::endl;
	try
	{
		std::cout << "Attempting to Create RobotomyRequestForm: casey, notSigned, gradeToSign(72), gradeToExecute(45)" << std::endl;
		RobotomyRequestForm	form("casey");
		Bureaucrat	alice("Alice", 72);
		alice.signForm(form);
		Bureaucrat	bob("Bob", 46);

		bob.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	std::cout << "TESTING FAILED PRESIDENTIAL FORM EXECUTION: executor bob grade is too low" << std::endl;
	try
	{
		std::cout << "Attempting to Create PresidentialPardonForm: casey, notSigned, gradeToSign(25), gradeToExecute(5)" << std::endl;
		PresidentialPardonForm	form("Casey");
		Bureaucrat	alice("Alice", 24);
		alice.signForm(form);
		Bureaucrat	bob("Bob", 6);
		
		std::cout << "bob.executeForm(form)" << std::endl;
		bob.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	std::cout << "TESTING FAILED SHRUBBERY FORM EXECUTION: form is not signed" << std::endl;
	try
	{
		std::cout << "Attempting to Create ShrubberyCreationForm: failedschool, notSigned, gradeToSign(145), gradeToExecute(137)" << std::endl;
		ShrubberyCreationForm	form("failedschool");
		Bureaucrat	bob("Bob", 137);

		bob.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	std::cout << "TESTING FAILED ROBOTOMY FORM EXECUTION: form is not signed" << std::endl;
	try
	{
		std::cout << "Attempting to Create RobotomyRequestForm: casey, notSigned, gradeToSign(72), gradeToExecute(45)" << std::endl;
		ShrubberyCreationForm	form("casey");
		Bureaucrat	bob("Bob", 30);

		bob.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printFooter();
}
