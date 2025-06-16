#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap tom("Tom");
	ScavTrap jerry("Jerry");


	tom.attack("Jerry");
	tom.takeDamage(10);
	tom.beRepaired(10);
	jerry.guardGate();

	/////////////////////
	FragTrap fatima("Fatima");
	FragTrap fiona("Fiona");

	fiona.attack("Jerry");
	fiona.takeDamage(10);
	fiona.beRepaired(10);
	fatima.highFivesGuys();
}
