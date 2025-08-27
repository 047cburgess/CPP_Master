#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name)
{
	this->_weapon = NULL;
};

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have any weapon to attack :(" << std::endl;
}

void	HumanB::setWeapon(Weapon& wep)
{
	this->_weapon = &wep;
}
