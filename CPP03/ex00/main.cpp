#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	tom("Tom");
	ClapTrap	jerry("Jerry");
	ClapTrap	c;
	
	tom.attack("Jerry");
	jerry.takeDamage(tom.getAttackDamage());
	jerry.beRepaired(5);
	tom.takeDamage(500);
	tom.attack("Jerry");
	tom.beRepaired(1000);
	tom.attack("Jerry");
	jerry.attack("Tom");
	tom.attack("Jerry");
	tom.attack("Jerry");
	tom.attack("Jerry");
	tom.attack("Jerry");
	tom.attack("Jerry");
	tom.attack("Jerry");
	tom.attack("Jerry");
	tom.attack("Jerry");

	return (0);
}
