#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class	Cat: public Animal
{
	protected:
		std::string	type;
	public:
		// Constructors
		Cat(); //default
		Cat(const Cat& other); // copy
		~Cat(); //destructor
		
		Cat&	operator=(const Cat& other); // copy assignment

		// Public Member Functions
		void	makeSound(void) const;
};

# endif
