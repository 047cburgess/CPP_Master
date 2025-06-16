#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	std::cout << "Constructor called for ScavTrap " << this->getName() << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->logStatus();
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called for ScavTrap" << std::endl;
	this->logStatus();
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called for ScavTrap " << this->getName() << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "Copy assignment operator called Scav Trap" << std::endl;
	if (this != &rhs)
	{
	      ClapTrap::operator=(rhs);
	}
	this->logStatus();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const ScavTrap& instance)
{
	os << "-Name: " << instance.getName() << std::endl;
	os << "-Hit Points: " << instance.getHitPoints() << std::endl;
	os << "-EnergyPoints: " << instance.getEnergyPoints() << std::endl;
	os << "-AttackDamage: " << instance.getAttackDamage() << std::endl;
	return (os);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " failed to attack " << target << ". "
			<< "Not enough resources!" << std::endl;
		this->logStatus();
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	this->logStatus();
}
