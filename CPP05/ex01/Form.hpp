#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	_name;
		bool	_isSigned;
		const int	_signGrade;
		const int	_executeGrade;
		const static int	_gradeMax = 1;
		const static int	_gradeMin = 150;

		Form();
		Form&	operator=(const Form& other);
	public:
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& other);
		~Form();
		const std::string&	getName(void) const;
		const bool&	getIsSigned(void) const;
		const int&	getSignGrade(void) const;
		const int&	getExecuteGrade(void) const;
		void	beSigned(Bureaucrat& bureaucrat);

		class	GradeTooHighException:	public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException:	public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);
	
# endif
