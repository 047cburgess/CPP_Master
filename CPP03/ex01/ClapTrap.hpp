#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap
{
	protected:
		std::string	_name;
		int	_hitPoints;
		int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		// Constructors
		ClapTrap(void); // default constructor
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap(void);
		ClapTrap&	operator=(const ClapTrap &rhs);


		// Member functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		unsigned int	getAttackDamage(void) const;
		int	getEnergyPoints(void) const;
		int	getHitPoints(void) const;
		std::string	getName(void) const;
		void	logStatus(void) const;
		void	setHitPoints(unsigned int amount);
		void	setEnergyPoints(unsigned int amount);
		void	setAttackDamage(unsigned int amount);
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& instance);

# endif
