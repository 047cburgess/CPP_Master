#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	PresidentialPardonForm: public AForm
{
	private:
		static const int	_signGrade = 25;
		static const int	_executeGrade = 5;
		std::string	_target;
		PresidentialPardonForm();
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	public:
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();

		void	beExecuted(void) const;
		const std::string&	getTarget() const;

};	
# endif
