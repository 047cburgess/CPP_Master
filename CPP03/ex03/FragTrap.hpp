#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
{
	protected:
		static const int _startHitPoints = 10; 
		static const int _startEnergyPoints = 10; 
		static const int _startAttackDamage = 0; 
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
