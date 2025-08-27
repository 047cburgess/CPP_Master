#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wep): _name(name), _weapon(wep) {};

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
