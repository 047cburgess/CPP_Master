#include "ClapTrap.hpp"
#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "Default FragTrap constructor called." << std::endl;
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->logStatus();
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	std::cout << "Constructor called for FragTrap " << this->getName() << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->logStatus();
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called for FragTrap" << std::endl;
	this->logStatus();
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called for FragTrap " << this->getName() << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "Copy assignment operator called FragTrap" << std::endl;
	if (this != &rhs)
	{
	      ClapTrap::operator=(rhs);
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const FragTrap& instance)
{
	os << "-Name: " << instance.getName() << std::endl;
	os << "-Hit Points: " << instance.getHitPoints() << std::endl;
	os << "-EnergyPoints: " << instance.getEnergyPoints() << std::endl;
	os << "-AttackDamage: " << instance.getAttackDamage() << std::endl;
	return (os);
}

void	FragTrap::attack(const std::string& target)
{
	
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " failed to attack " << target << ". "
			<< "Not enough resources!" << std::endl;
		this->logStatus();
		return;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	this->logStatus();
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " high fives everyone!" << std::endl;
}
