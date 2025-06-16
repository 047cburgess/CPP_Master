#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void); // default constructor
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap(void);
		ScavTrap&	operator=(const ScavTrap &rhs);

		// Member functions
		void	guardGate(void);
		void	attack(const std::string& target);
};


# endif
