#ifndef PRESEDENTIALPARDON_HPP
# define PRESEDENTIALPARDON_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	PresedentialPardonForm: public AForm
{
	private:
		static const int	_signGrade = 25;
		static const int	_executeGrade = 5;
		PresedentialPardonForm();
		PresedentialPardonForm&	operator=(const PresedentialPardonForm& other);
	public:
		PresedentialPardonForm(std::string name);
		PresedentialPardonForm(const PresedentialPardonForm& other);
		virtual ~PresedentialPardonForm();

		void	beExecuted(void) const;

};	
# endif
