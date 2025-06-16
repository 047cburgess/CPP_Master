#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(void): ClapTrap()
{
	std::cout << "Default DiamondTrap constructor called." << std::endl;
	this->_name = "default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->logStatus();
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "Constructor called for DiamondTrap " << name << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "HERE";
	this->logStatus();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called for DiamondTrap" << std::endl;
	this->logStatus();
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor called for DiamondTrap " << this->_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "Copy assignment operator called Diamond Trap" << std::endl;
	if (this != &rhs)
	{
	      ClapTrap::operator=(rhs);
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const DiamondTrap& instance)
{
	os << "-Name: " << instance.getName() << std::endl;
	os << "-Hit Points: " << instance.getHitPoints() << std::endl;
	os << "-EnergyPoints: " << instance.getEnergyPoints() << std::endl;
	os << "-AttackDamage: " << instance.getAttackDamage() << std::endl;
	return (os);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "ClapTrap Name: " << ClapTrap::_name << std::endl;
}
