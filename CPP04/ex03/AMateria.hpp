#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	private:
		AMateria();

	protected:
		std::string type;

	public:
		AMateria(std::string const & type); // parametric
		AMateria(const AMateria& other); // copy
		virtual ~AMateria(); // destructor
		
		AMateria&	operator=(const AMateria& other); // copy assignment
		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
#endif
