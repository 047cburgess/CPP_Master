#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	private:
		static const int	_signGrade = 145;
		static const int	_executeGrade = 137;
		ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	public:
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		void	beExecuted(void) const;

};	
# endif
