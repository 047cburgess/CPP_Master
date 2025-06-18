#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain
{
	public:
		std::string ideas[100];
		Brain();
		~Brain();
		Brain(const Brain& other); // copy
		Brain&	operator=(const Brain& other); // copy assignment
};
#endif
