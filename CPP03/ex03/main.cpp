#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	/////////////////////////
	DiamondTrap donna("Donna");
	DiamondTrap dina("Dina");

	donna.whoAmI();

	donna.attack("Dina");
	donna.takeDamage(10);
	donna.guardGate();
	donna.highFivesGuys();
	donna.beRepaired(10);
	dina.whoAmI();
}
