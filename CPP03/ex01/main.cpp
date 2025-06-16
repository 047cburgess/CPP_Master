#include <iostream>
#include <string>
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap tom("Tom");
	ScavTrap jerry("Jerry");
	ScavTrap tom2 = tom;
	ScavTrap molly(jerry);


	tom.attack("Jerry");
	tom.takeDamage(10);
	tom.beRepaired(10);
	jerry.guardGate();
	tom2.takeDamage(2);

}
