#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("default"), _isSigned(false), _signGrade(1), _executeGrade(1)
{
	return ;
}

AForm::AForm(std::string name, int signGrade, int executeGrade): _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < _gradeMax || executeGrade < _gradeMax)
		throw	GradeTooHighException();
	if (executeGrade > _gradeMin || executeGrade > _gradeMin)
		throw 	GradeTooLowException();
}

AForm::AForm(const AForm& other): _name(other.getName()), _isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	return ;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_isSigned = other.getIsSigned();
	}
	return (*this);	
}

AForm::~AForm(void)
{
	return ;
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "[AForm] | name = " << form.getName();
	os << " | isSigned = " << (form.getIsSigned() ? "yes" : "no");
	os << " | signGrade = " << form.getSignGrade();
	os << " | executeGrade = " << form.getExecuteGrade();
	return (os);
}

const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

const bool&	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

const int&	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

const int&	AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("A GradeTooHighException was thrown.");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("A GradeTooLowException was thrown.");
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return ("AForm is already signed.");
}

const char*	AForm::NotSignedException::what() const throw()
{
	return ("AForm is not signed.");
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_isSigned)
		throw	AlreadySignedException();
	if (bureaucrat.getGrade() > this->_signGrade)
		throw	GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw	NotSignedException();
	if (executor.getGrade() > this->_executeGrade)
		throw	GradeTooLowException();
	this->beExecuted();
}
