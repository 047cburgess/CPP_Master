#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class	Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;
		Bureaucrat(); // default
		const static int	_gradeMax = 1;
		const static int	_gradeMin = 150;
	public:
		Bureaucrat(std::string name, int grade); //parametric
		Bureaucrat(const Bureaucrat& other); // copy
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& other); // copy assignment
		const std::string&	getName(void) const;
		const int&		getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(Form& form);

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

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& who);

# endif
