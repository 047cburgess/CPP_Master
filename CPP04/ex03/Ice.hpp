#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Ice: public AMateria
{
	public:
		Ice(); // default constructor
		Ice(const Ice & other);
		~Ice(); // destructor
		Ice&	operator=(const Ice &other);

		AMateria*	clone() const;
		void	use(ICharacter& target);
};
# endif
