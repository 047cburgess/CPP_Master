# include "Bureaucrat.hpp"
# include "Form.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(_gradeMin)
{
	std::cout << "Successfully constructed " << *this << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < _gradeMax)
		throw	Bureaucrat::GradeTooHighException();
	if (grade > _gradeMin)
		throw 	Bureaucrat::GradeTooLowException();
	std::cout << "Successfully constructed " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other.getName()), _grade(other.getGrade())
{
	std::cout << "Successfully constructed " << *this << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << *this << "was destroyed" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& instance)
{
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << ".";
	return (os);
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int&	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == _gradeMax)
		throw	GradeTooHighException();
	this->_grade -= 1;
	std::cout << *this << "(Grade was increased by 1)" << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == _gradeMin)
		throw	GradeTooLowException();
	this->_grade += 1;
	std::cout << *this << "(Grade was decreased by 1)" << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("A GradeTooHighException was thrown");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("A GradeTooLowException was thrown");
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << _name << " signed " << form << std::endl;
	}
	catch( std::exception &e)
	{
		std::cout << "Bureaucrat " << _name << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}
