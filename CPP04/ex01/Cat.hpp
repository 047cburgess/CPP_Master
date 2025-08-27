#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
	private:
		Brain*	brain;
	public:
		// Constructors
		Cat(); //default
		Cat(const Cat& other); // copy
		~Cat(); //destructor
		
		Cat&	operator=(const Cat& other); // copy assignment

		// Public Member Functions
		void	makeSound(void) const;
		Brain*	getBrain(void) const;
};

# endif
