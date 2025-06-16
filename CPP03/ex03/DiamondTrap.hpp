#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include <string>
# include <iostream>

class	DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(void); // default constructor
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap(void);
		DiamondTrap&	operator=(const DiamondTrap &rhs);

		// Member function
		void	whoAmI(void);
		void	attack(const std::string& target);
};

#endif
