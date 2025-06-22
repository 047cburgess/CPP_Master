#include "Bureaucrat.hpp"
#include "Form.hpp"


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
	std::cout << "TESTING SUCCESSFUL CREATION OF FORM" << std::endl;
	try
	{
		std::cout << "Attempting to Create Form: MyForm, notSigned, gradeToSign(20), gradeToExecute(1)" << std::endl;
		Form	form("MyForm", 20, 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	std::cout << "TESTING FAILED CREATION OF FORM: GRADE OUT OF BOUNDS" << std::endl;
	try
	{
		std::cout << "Attempting to Create Form: MyForm, notSigned, gradeToSign(0), gradeToExecute(151)" << std::endl;
		Form	form("MyForm", 0, 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	std::cout << "TESTING FAILED CREATION OF FORM: GRADE OUT OF BOUNDS & trycatch demo" << std::endl;
	try
	{
		std::cout << "Attempting to Create Form: MyForm, notSigned, gradeToSign(20), gradeToExecute(151)" << std::endl;
		Form	form("MyForm", 20, 151);
		std::cout << "Attempting to Create Form: NOTCREATED, notSigned, gradeToSign(1), gradeToExecute(1)" << std::endl;
		Form	notcreated("NOTCREATED", 1, 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	printDivider();

	std::cout << "TESTING SUCCESSFULLY SIGNED FORM" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 19);
		std::cout << "Attempting to Create Form: MyForm, notSigned, gradeToSign(20), gradeToExecute(1)" << std::endl;
		Form	form("MyForm", 20, 1);
		std::cout << "Alice attempting to sign form" << std::endl;
		alice.signForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	printDivider();

	{
		std::cout << "TESTING FAILED SIGNED FORM: GRADE TOO LOW" << std::endl;
		Bureaucrat alice("Alice", 25);
		Form	form("MyForm", 20, 1);
		std::cout << "Alice attempting to sign form" << std::endl;
		alice.signForm(form);

	}
	printDivider();
	{
		std::cout << "TESTING FAILED SIGNED FORM: ALREADY SIGNED" << std::endl;
		Bureaucrat alice("Alice", 25);
		Bureaucrat bob("Bob", 1);
		Form	form("MyForm", 20, 1);
		bob.signForm(form);
		std::cout << "Alice attempting to sign form" << std::endl;
		alice.signForm(form);
	}
	printDivider();
	
	{
		std::cout << "TESTING FAILED SIGNED FORM THEN SUCCESSFUL" << std::endl;
		Bureaucrat alice("Alice", 2);
		Form	form("MyForm", 1, 1);
		std::cout << alice << "attemping to sign form but her grade is too low" << std::endl;
		alice.signForm(form);
		alice.incrementGrade();
		std::cout << alice << "attemping to resign form, will try both times as is not in a try catch statement" << std::endl;
		alice.signForm(form);
		std::cout << alice << "attemping to resign form, will try both times as is not in a try catch statement" << std::endl;
		alice.signForm(form);
	}
	printDivider();

	{
		std::cout << "TESTING FORM OUTPUT OVERLOAD <<" << std::endl;
		Form	form("MyForm", 20, 1);
		std::cout << "std::cout << form << std::endl" << std::endl;
		std::cout << form << std::endl;
	}
	
	printDivider();
	printFooter();
}
