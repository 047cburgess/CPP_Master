#include "ClapTrap.hpp"
#include <iostream>

// Constructors
ClapTrap::ClapTrap(void): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Name Constructor called for ClapTrap " << name << std::endl;
	this->logStatus();
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
	this->logStatus();
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for Clap Trap " << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	this->logStatus();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& instance)
{
	os << "-Name: " << instance.getName() << std::endl;
	os << "-Hit Points: " << instance.getHitPoints() << std::endl;
	os << "-EnergyPoints: " << instance.getEnergyPoints() << std::endl;
	os << "-AttackDamage: " << instance.getAttackDamage() << std::endl;
	return (os);
}

// Member Functions
void	ClapTrap::logStatus(void) const
{
	std::cout << *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " failed to attack " << target << ". "
			<< "Not enough resources!" << std::endl;
		this->logStatus();
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	this->logStatus();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " was attacked, losing " << amount << " hit points!" << std:: endl;
	this->_hitPoints -= amount;
	this->logStatus();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " failed to repair itself: not enough energy points!" << std::endl;
		this->logStatus();
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself, gaining " << amount << " hit points!" << std:: endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	this->logStatus();
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}
