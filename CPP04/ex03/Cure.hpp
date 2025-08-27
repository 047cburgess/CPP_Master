#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Cure: public AMateria
{
	public:
		Cure(); // default constructor
		Cure(const Cure & other);
		~Cure(); // destructor
		Cure&	operator=(const Cure &other);

		AMateria*	clone() const;
		void	use(ICharacter& target);
};
# endif
