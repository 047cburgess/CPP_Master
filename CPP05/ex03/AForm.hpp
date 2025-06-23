#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;
class	AForm
{
	private:
		const std::string	_name;
		bool	_isSigned;
		const int	_signGrade;
		const int	_executeGrade;
		const static int	_gradeMax = 1;
		const static int	_gradeMin = 150;

	public:
		AForm();
		AForm&	operator=(const AForm& other);
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& other);
		virtual ~AForm();

		const std::string&	getName(void) const;
		const bool&	getIsSigned(void) const;
		const int&	getSignGrade(void) const;
		const int&	getExecuteGrade(void) const;
		virtual	void	beExecuted(void) const = 0;
		void	beSigned(Bureaucrat& bureaucrat);
		void	execute(Bureaucrat const & executor) const;

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
		class	AlreadySignedException:	public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	NotSignedException:	public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	FailedFileStreamException:	public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);
	
# endif
