#include "Bureaucrat.hpp"


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
	std::cout << "TESTING SUCCESSFUL CREATION OF BUREAUCRAT" << std::endl;
	try
	{
		std::cout << "Attempting to Create Bureaucrat: Alice, Grade: 1" << std::endl;
		Bureaucrat alice("Alice", 1);
		std::cout << "Success" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Failed to create Bureaucrat Alice";
	}
	
	printDivider();
	std::cout << "TESTING CREATION WITH GRADE TOO LOW" << std::endl;
	try
	{
		std::cout << "Attempting to Create Bureaucrat: Alice, Grade: 151" << std::endl;
		Bureaucrat alice("Alice", 151);
		std::cout << "Success" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Failed to create Bureaucrat Alice" << std::endl;
	}

	printDivider();
	std::cout << "TESTING CREATION WITH GRADE TOO HIGH" << std::endl;
	try
	{
		std::cout << "Attempting to Create Bureaucrat: Alice, Grade: 0" << std::endl;
		Bureaucrat alice("Alice", 0);
		std::cout << "Success" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Failed to create Bureaucrat Alice" << std::endl;
	}

	printDivider();
	std::cout << "TESTING SUCCESSFUL INCREMENT OF GRADE" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 2);

		std::cout << "Attempting to Increase Alice grade from 2 to 1" << std::endl;
		alice.incrementGrade();
		std::cout << "Success: Alice grade is now " << alice.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Failed to increment Alice grade" << std::endl;
	}

	printDivider();
	std::cout << "TESTING SUCCESSFUL DECREMENT OF GRADE" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 2);

		std::cout << "Attempting to decrease Alice grade from 2 to 3" << std::endl;
		alice.decrementGrade();
		std::cout << "Success: Alice grade is now " << alice.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Failed to decrement Alice grade" << std::endl;
	}

	printDivider();
	std::cout << "TESTING FAILED INCREMENT OF GRADE" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);

		std::cout << "Attempting to increment Alice grade from 1 to 0" << std::endl;
		alice.incrementGrade();
		std::cout << "Success: Alice grade is now " << alice.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Failed to increment Alice grade" << std::endl;
	}

	printDivider();
	std::cout << "TESTING FAILED DECREMENT OF GRADE" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 150);

		std::cout << "Attempting to decrease Alice grade from 150 to 151" << std::endl;
		alice.decrementGrade();
		std::cout << "Success: Alice grade is now " << alice.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Failed to decrement Alice grade" << std::endl;
	}

	printDivider();
	std::cout << "TESTING BUREAUCRAT OVERLOAD OPERATOR" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		std::cout << "Attempting to execute code: 'std::cout << alice << std::endl'" << std::endl;
		std::cout << alice << std::endl;
		std::cout << "Success" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	printFooter();
}
