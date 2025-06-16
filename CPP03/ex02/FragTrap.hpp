#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		FragTrap(void); // default constructor
		FragTrap(const std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap(void);
		FragTrap&	operator=(const FragTrap &rhs);

		// Member functions
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};


# endif
