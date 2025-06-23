#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

class	Intern
{
	private:
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		AForm*	createPresidential(const std::string& target);
		AForm*	createShrubbery(const std::string& target);
		AForm*	createRobotomy(const std::string& target);
	public:
		Intern();
		~Intern();
		AForm*	makeForm(const std::string& name, const std::string& target);
};

#endif
