#include "Form.hpp"

Form::Form(void): _name("default"), _isSigned(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "Default Form constructor called: " << *this << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade): _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < _gradeMax || executeGrade < _gradeMax)
		throw	GradeTooHighException();
	if (executeGrade > _gradeMin || executeGrade > _gradeMin)
		throw 	GradeTooLowException();
	std::cout << "Successfully constructed: " << *this << std::endl;
}

Form::Form(const Form& other): _name(other.getName()), _isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	std::cout << "Successfully constructed: " << *this << std::endl;
	return ;
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_isSigned = other.getIsSigned();
	}
	return (*this);	
}

Form::~Form(void)
{
	std::cout << "Form destroyed: " << *this << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "[Form] | name = " << form.getName();
	os << " | isSigned = " << (form.getIsSigned() ? "yes" : "no");
	os << " | signGrade = " << form.getSignGrade();
	os << " | executeGrade = " << form.getExecuteGrade();
	return (os);
}

const std::string&	Form::getName(void) const
{
	return (this->_name);
}

const bool&	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

const int&	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

const int&	Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("A GradeTooHighException was thrown.");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("A GradeTooLowException was thrown.");
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed.");
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_isSigned)
		throw	AlreadySignedException();
	if (bureaucrat.getGrade() > this->_signGrade)
		throw	GradeTooLowException();
	this->_isSigned = true;
}
