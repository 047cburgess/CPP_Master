#ifndef ROBOTOMYCREATIONFORM_HPP
# define ROBOTOMYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	private:
		static const int	_signGrade = 72;
		static const int	_executeGrade = 45;
		RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	public:
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		void	beExecuted(void) const;

};	
# endif
